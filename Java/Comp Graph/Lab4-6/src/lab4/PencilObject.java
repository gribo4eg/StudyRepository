package lab4;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.universe.SimpleUniverse;
import javax.media.j3d.*;
import javax.swing.Timer;
import javax.vecmath.*;

public class PencilObject implements ActionListener {

    private TransformGroup pencilTransformGroup;
    private Transform3D pencilTransform3D = new Transform3D();
    private Timer timer;
    private float angle = 0;

    public static void main(String[] args) throws Exception {
        new PencilObject();
    }


    public PencilObject() throws Exception {
        timer = new Timer(60, this);
        timer.start();
        BranchGroup scene = createSceneGraph();
        SimpleUniverse u = new SimpleUniverse();
        u.getViewingPlatform().setNominalViewingTransform();
        u.addBranchGraph(scene);
    }

    public BranchGroup createSceneGraph() throws Exception {
        BranchGroup objRoot = new BranchGroup();

        pencilTransformGroup = new TransformGroup();
        pencilTransformGroup.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
        pencilTransform3D.setTranslation(new Vector3f(.0f,.0f,.0f));
        pencilTransformGroup.setTransform(pencilTransform3D);
        buildPencil();
        objRoot.addChild(pencilTransformGroup);

        BoundingSphere bounds = new BoundingSphere(new Point3d(0.0, 0.0, 0.0),100.0);
        Color3f light1Color = new Color3f(1.0f, .5f, .4f);
        Vector3f light1Direction = new Vector3f(4.0f, -7.0f, -12.0f);
        DirectionalLight light1 = new DirectionalLight(light1Color,
                light1Direction);
        light1.setInfluencingBounds(bounds);
        objRoot.addChild(light1);

        return objRoot;
    }

    private void buildPencil() throws Exception {

        addPart(PencilPart.getCylinder(0.5f,0.1f, new Color3f(0.5f,0.5f,0.0f)), 0.0f,0.0f,0.0f);

        addPart(PencilPart.getCone(0.25f,0.100f, new Color3f(1.0f,0.0f,0.0f)), 0.0f, 0.37f, 0.0f);

        addPart(PencilPart.getCone(0.1f,0.04f, new Color3f(0.f,1.f,1.f)),0.0f,0.449f, 0.0f);

        addPart(PencilPart.getCylinder(0.07f, 0.100f, new Color3f(1.f,0.f,.5f)), 0.0f, -0.27f, 0.0f);

        addPart(PencilPart.getSphere(0.098f, new Color3f(.0f,.0f,1.f)),0.0f,-0.30f,0.0f);
    }

    private void addPart(Node node, float x, float y, float z) {
        TransformGroup tg = new TransformGroup();
        Transform3D transform = new Transform3D();
        Vector3f vector = new Vector3f(x, y, z);
        transform.setTranslation(vector);
        tg.setTransform(transform);
        tg.addChild(node);
        pencilTransformGroup.addChild(tg);
    }

        @Override
    public void actionPerformed(ActionEvent e) {
        pencilTransform3D.rotY(angle);
        pencilTransformGroup.setTransform(pencilTransform3D);
        angle += 0.05;
    }
}

class PencilPart {

    public static Cone getCone(float height, float radius, Color3f emissivColor) {
        int primFlags = Primitive.GENERATE_NORMALS + Primitive.GENERATE_TEXTURE_COORDS;
        return new Cone(radius, height, primFlags, getAppearence(emissivColor));
    }

    public static Cylinder getCylinder(float height, float radius, Color3f emissivColor) {
        int primFlags = Primitive.GENERATE_NORMALS + Primitive.GENERATE_TEXTURE_COORDS;
        return new Cylinder(radius, height, primFlags, getAppearence(emissivColor));
    }

    public static Sphere getSphere(float radius, Color3f emissiveColor) {
        int primflags = Primitive.GENERATE_NORMALS + Primitive.GENERATE_TEXTURE_COORDS;
        return new Sphere(radius, primflags, getAppearence(emissiveColor));
    }

    private static Appearance getAppearence(Color3f emissive) {
        Appearance ap = new Appearance();
        Color3f ambient = new Color3f(0.2f, 0.15f, .15f);
        Color3f diffuse = new Color3f(1.2f, 1.15f, .15f);
        Color3f specular = new Color3f(0.0f, 0.0f, 0.0f);
        ap.setMaterial(new Material(ambient, emissive, diffuse, specular, 1.0f));

        return ap;
    }
}