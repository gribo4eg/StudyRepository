package lab5;

import javafx.scene.input.KeyCode;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.media.j3d.*;
import javax.swing.JFrame;
import javax.swing.Timer;
import javax.vecmath.*;

public class BoatAnimation implements ActionListener, KeyListener {
    private TransformGroup boat;
    private Transform3D translateTransform;
    private Transform3D rotateTransformX;
    private Transform3D rotateTransformY;

    private JFrame mainFrame;

    private float speed = 0.005f;
    private float x = 0;
    private float y = 0;
    private float angle = 0;

    private boolean w = false;
    private boolean s = false;
    private boolean a = false;
    private boolean d = false;
    private boolean auto = false;
    private Timer timer;

    public BoatAnimation(TransformGroup boat, Transform3D trans, JFrame frame){
        this.boat = boat;
        this.translateTransform=trans;
        this.mainFrame=frame;

        rotateTransformX= new Transform3D();
        rotateTransformY= new Transform3D();

        FirstMainClass.canvas.addKeyListener(this);
        timer = new Timer(100, this);

        Panel p =new Panel();
        mainFrame.add("North",p);
        timer.start();

        rotateTransformX.rotX(Math.PI/2);
        translateTransform.mul(rotateTransformX);
        rotateTransformY.rotY(Math.PI);
        translateTransform.mul(rotateTransformY);

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        Move();
    }

    private void Move() {
        float deltaAngle = 0.1f;

        if (w || auto) {
            x -= speed * Math.sin(angle);
            y += speed * Math.cos(angle);
            deltaAngle = 0.1f;
        }

        if (s) {
            x += speed * Math.sin(angle);
            y -= speed * Math.cos(angle);
            deltaAngle = -0.1f;
        }

        translateTransform.setTranslation(new Vector3f(x, y, 0));

        if (a) {
            angle += deltaAngle;
            Transform3D rotation = new Transform3D();
            rotation.rotY(deltaAngle);
            translateTransform.mul(rotation);
        }

        if (d) {
            angle -= deltaAngle;
            Transform3D rotation = new Transform3D();
            rotation.rotY(-deltaAngle);
            translateTransform.mul(rotation);
        }

        boat.setTransform(translateTransform);
    }

    @Override
    public void keyTyped(KeyEvent e) {
        //Invoked when a key has been typed.
    }

    @Override
    public void keyPressed(KeyEvent e) {
        switch (e.getKeyChar()) {
            case 'w': w = true; break;
            case 's': s = true; break;
            case 'a': a = true; break;
            case 'd': d = true; break;
            case 'q': auto = !auto; break;
            case '1': speed = 0.01f; break;
            case '2': speed = 0.02f; break;
            case '3': speed = 0.03f; break;
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {
        switch (e.getKeyChar()) {
            case 'w': w = false; break;
            case 's': s = false; break;
            case 'a': a = false; break;
            case 'd': d = false; break;
        }
    }

}