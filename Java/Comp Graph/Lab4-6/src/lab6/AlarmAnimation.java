package lab6;

import javax.vecmath.*;
import javax.media.j3d.*;
import javax.swing.JFrame;

import com.sun.j3d.utils.behaviors.vp.OrbitBehavior;
import com.sun.j3d.utils.universe.*;
import com.sun.j3d.loaders.*;
import com.sun.j3d.loaders.objectfile.*;
import com.sun.j3d.utils.image.TextureLoader;

import java.awt.BorderLayout;
import java.io.FileReader;
import java.io.IOException;
import java.util.Map;

public class AlarmAnimation extends JFrame {

    public AlarmAnimation() throws IOException {
        configureWindow();

        Canvas3D canvas = new Canvas3D(SimpleUniverse.getPreferredConfiguration());
        getContentPane().add(canvas, BorderLayout.CENTER);

        SimpleUniverse universe = new SimpleUniverse(canvas);
        universe.getViewingPlatform().setNominalViewingTransform();

        OrbitBehavior ob = new OrbitBehavior(canvas);
        ob.setSchedulingBounds(new BoundingSphere(new Point3d(0.0,0.0,0.0),Double.MAX_VALUE));
        universe.getViewingPlatform().setViewPlatformBehavior(ob);

        BranchGroup root = new BranchGroup();

        addDirectionalLight(root);
        addImageBackground(root);
        root.addChild(getMainGroup());

        root.compile();
        universe.addBranchGraph(root);
        setVisible(true);
    }

    private void configureWindow() {
        setTitle("Helicopter");
        setExtendedState(JFrame.MAXIMIZED_BOTH);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    private void addDirectionalLight(BranchGroup root) {
        BoundingSphere bounds = new BoundingSphere();
        bounds.setRadius(100);

        DirectionalLight light = new DirectionalLight(new Color3f(1, 1, 1), new Vector3f(-1, -1, -1));
        light.setInfluencingBounds(bounds);

        root.addChild(light);
    }

    private void addImageBackground(BranchGroup root) {
        Background background = new Background(new Color3f(1.0f,1.0f,1.0f));
        BoundingSphere bounds = new BoundingSphere(new Point3d(0.0, 0.0, 0.0), 100.0);
        background.setApplicationBounds(bounds);
        root.addChild(background);
    }

    private BranchGroup getMainGroup() throws IOException {
        Scene scene = getSceneFromFile("/home/alexander/Documents/Java/models/helicopter.obj");
        Map<String, Shape3D> map = scene.getNamedObjects();
        printModelElementsList(map);

        Shape3D propeller1 = map.get("big_propeller");

        Shape3D propeller2 = map.get("small_propeller");

        BranchGroup group = scene.getSceneGroup();

        // propeller1
        group.removeChild(propeller1);

        Transform3D transform1 = new Transform3D();
        transform1.setTranslation(new Vector3f(0, 0, -0.21f));

        TransformGroup tg1 = getRotationTransformGroup(propeller1, transform1);
        group.addChild(tg1);

        // propeller2
        group.removeChild(propeller2);

        Transform3D transformZ = new Transform3D();
        transformZ.rotZ(Math.PI / 2);

        Transform3D transform2 = new Transform3D();
        transform2.setTranslation(new Vector3f(0, 0.065f, 0.84745f));
        transform2.mul(transformZ);

        TransformGroup tg2 = getRotationTransformGroup(propeller2, transform2);
        group.addChild(tg2);

        BranchGroup root = new BranchGroup();

        root.addChild(getGroupWithMainTransform(group));

        return root;
    }

    private TransformGroup getRotationTransformGroup(Node node, Transform3D transform) {
        TransformGroup tg = new TransformGroup();

        Alpha alpha = new Alpha(-1, Alpha.INCREASING_ENABLE, 0, 0, 250, 0, 0, 0, 0, 0);
        RotationInterpolator rotation = new RotationInterpolator(alpha, tg, transform, (float) Math.PI * 2, 0);
        BoundingSphere bs = new BoundingSphere(new Point3d(0, 0, 0), Double.MAX_VALUE);
        rotation.setSchedulingBounds(bs);

        tg.addChild(node);
        tg.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
        tg.addChild(rotation);

        return tg;
    }

    private TransformGroup getGroupWithMainTransform(Node node) {
        Transform3D translationY = new Transform3D();
        translationY.rotY(Math.PI / 2);

        Transform3D translationS = new Transform3D();
        translationS.setTranslation(new Vector3f(0, 0, -7));
        translationS.mul(translationY);

        TransformGroup tg = new TransformGroup();
        tg.setTransform(translationS);
        tg.addChild(node);

        return tg;
    }

    private TransformGroup getGroupWithHelicopterMoveTransform(Node node) {
        TransformGroup tg = new TransformGroup();

        Transform3D transform = new Transform3D();
        BoundingSphere bs = new BoundingSphere(new Point3d(0.0,0.0,0.0), Double.MAX_VALUE);

        Alpha alpha = new Alpha(-1, Alpha.INCREASING_ENABLE, 0, 0, 10000, 0, 0, 0, 0, 0);
        PositionInterpolator position = new PositionInterpolator(alpha, tg, transform, 7, -5);
        position.setSchedulingBounds(bs);
        tg.addChild(position);

        tg.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
        tg.addChild(node);

        return tg;
    }

    private TransformGroup getGroupWithMissileMoveTransform(Node node) {
        TransformGroup tg = new TransformGroup();

        Transform3D transform = new Transform3D();
        BoundingSphere bs = new BoundingSphere(new Point3d(0.0,0.0,0.0), Double.MAX_VALUE);

        Alpha alpha1 = new Alpha(-1, Alpha.INCREASING_ENABLE, 0, 0, 5833, 0, 4167, 0, 0, 0);
        PositionInterpolator position1 = new PositionInterpolator(alpha1, tg, transform, 7, 0);
        position1.setSchedulingBounds(bs);
        tg.addChild(position1);

        Alpha alpha2 = new Alpha(-1, Alpha.INCREASING_ENABLE, 5833, 0, 1000, 0, 10000-1000, 0, 0, 0);
        PositionInterpolator position2 = new PositionInterpolator(alpha2, tg, transform, 0, -5);
        position2.setSchedulingBounds(bs);
        tg.addChild(position2);

        tg.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
        tg.addChild(node);

        return tg;
    }

    private Scene getSceneFromFile(String path) throws IOException {
        ObjectFile file = new ObjectFile(ObjectFile.RESIZE);
        file.setFlags(ObjectFile.RESIZE | ObjectFile.TRIANGULATE | ObjectFile.STRIPIFY);
        return file.load(new FileReader(path));
    }

    private void setColor(Shape3D shape, Color3f color) {
        Appearance app = new Appearance();
        app.setMaterial(new Material(color, color, color, color, 150.0f));
        shape.setAppearance(app);
    }

    private void printModelElementsList(Map<String, Shape3D> map) {
        for (String name : map.keySet()) {
            System.out.println("Name: " + name);
        }
    }

    public static void main(String[] args) {
        try {
            AlarmAnimation helicopter = new AlarmAnimation();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}