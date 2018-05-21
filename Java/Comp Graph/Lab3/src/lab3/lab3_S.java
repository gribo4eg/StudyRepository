package lab3;

import javafx.scene.paint.Color;
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.Stage;

import javafx.scene.shape.*;

import javafx.animation.TranslateTransition;
import javafx.animation.RotateTransition;
import javafx.animation.ScaleTransition;
import javafx.animation.ParallelTransition;
import javafx.util.Duration;





public class lab3_S extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        Group root = new Group();
        Scene scene = new Scene(root, 1000, 600);

        // HEAD --------------------------------------------------
        Ellipse dolHead = new Ellipse(150,160,52,50);
        dolHead.setStroke(Color.BLACK);
        dolHead.setStrokeWidth(1);
        dolHead.setFill(Color.web("4286f4"));
        //---------------------------------------------------------------------------------------------
        // NOSE --------------------------------------------------
        Ellipse dolNose = new Ellipse(170,170,55,20);
        dolNose.setStroke(Color.BLACK);
        dolNose.setStrokeWidth(1);
        dolNose.setFill(Color.web("4286f4"));

        Ellipse dolNose2 = new Ellipse(166,170,55,20);
        dolNose2.setFill(Color.web("4286f4"));
        //---------------------------------------------------------------------------------------------
        // BODY --------------------------------------------------
        Ellipse dolBody1 = new Ellipse(130,200,40,80);
        dolBody1.setFill(Color.web("4286f4"));

        Ellipse dolBody1Back = new Ellipse(130,200,41,81);
        dolBody1Back.setFill(Color.web("000000"));

        Ellipse dolBody2 = new Ellipse(141,260,30,60);
        dolBody2.setFill(Color.web("4286f4"));

        RotateTransition rotateTransition = new RotateTransition(Duration.millis(1), dolBody2);
        rotateTransition.setByAngle(135f);
        rotateTransition.play();

        Ellipse dolBody2Back = new Ellipse(141,260,31,61);
        dolBody2Back.setFill(Color.web("000000"));

        rotateTransition = new RotateTransition(Duration.millis(1), dolBody2Back);
        rotateTransition.setByAngle(135f);
        rotateTransition.play();
        //---------------------------------------------------------------------------------------------
        // FIN --------------------------------------------------
        Polygon dolFin = new Polygon(100, 170, 60, 210, 100, 209);
        dolFin.setFill(Color.web("4286f4"));

        Polygon dolFinBack = new Polygon(99, 169, 59, 209, 101, 211);
        dolFinBack.setFill(Color.web("000000"));
        //---------------------------------------------------------------------------------------------
        // TAIL --------------------------------------------------
        Ellipse dolTail1 = new Ellipse(185,310,15,30);
        dolTail1.setFill(Color.web("4286f4"));

        Ellipse dolTail2 = new Ellipse(195,295,15,30);
        dolTail2.setFill(Color.web("4286f4"));

        rotateTransition = new RotateTransition(Duration.millis(1), dolTail2);
        rotateTransition.setByAngle(90f);
        rotateTransition.play();

        Ellipse dolTail1Back = new Ellipse(185,310,16,31);
        dolTail1Back.setFill(Color.web("000000"));

        Ellipse dolTail2Back = new Ellipse(195,295,16,31);
        dolTail2Back.setFill(Color.web("000000"));

        rotateTransition = new RotateTransition(Duration.millis(1), dolTail2Back);
        rotateTransition.setByAngle(90f);
        rotateTransition.play();
        //---------------------------------------------------------------------------------------------
        // EYES --------------------------------------------------
        Ellipse dolEyes1 = new Ellipse(165,147,7,7);
        dolEyes1.setStroke(Color.BLACK);
        dolEyes1.setStrokeWidth(2);
        dolEyes1.setFill(Color.web("ffffff"));

        Ellipse dolEyes2 = new Ellipse(185,147,7,7);
        dolEyes2.setStroke(Color.BLACK);
        dolEyes2.setStrokeWidth(2);
        dolEyes2.setFill(Color.web("ffffff"));

        Ellipse dolEyes1_2 = new Ellipse(169,148,4,4);
        dolEyes1_2.setFill(Color.web("000000"));

        Ellipse dolEyes2_2 = new Ellipse(183,148,4,4);
        dolEyes2_2.setFill(Color.web("000000"));
        //---------------------------------------------------------------------------------------------
        // MOUTH --------------------------------------------------
        Ellipse dolMouth = new Ellipse(160,190,12,11);
        dolMouth.setStroke(Color.BLACK);
        dolMouth.setStrokeWidth(1);
        dolMouth.setFill(Color.web("bf2a2a"));
        //---------------------------------------------------------------------------------------------
        // SPOT--------------------------------------------------
        Ellipse dolSpot1 = new Ellipse(110,170,7,7);
        dolSpot1.setFill(Color.web("9d43e8"));

        Ellipse dolSpot2 = new Ellipse(107,195,7,7);
        dolSpot2.setFill(Color.web("9d43e8"));

        Ellipse dolSpot3 = new Ellipse(110,220,7,7);
        dolSpot3.setFill(Color.web("9d43e8"));
        //---------------------------------------------------------------------------------------------
        // FINS --------------------------------------------------
        Arc dolFinRight1 = new Arc();
        dolFinRight1.setCenterX(180.0f);
        dolFinRight1.setCenterY(220.0f);
        dolFinRight1.setRadiusX(30.0f);
        dolFinRight1.setRadiusY(20.0f);
        dolFinRight1.setLength(180.0f);
        dolFinRight1.setType(ArcType.ROUND);
        dolFinRight1.setFill(Color.web("4286f4"));

        rotateTransition = new RotateTransition(Duration.millis(1), dolFinRight1);
        rotateTransition.setByAngle(50f);
        rotateTransition.play();

        Arc dolFinRightBack = new Arc();
        dolFinRightBack.setCenterX(180.0f);
        dolFinRightBack.setCenterY(220.0f);
        dolFinRightBack.setRadiusX(31.0f);
        dolFinRightBack.setRadiusY(21.0f);
        dolFinRightBack.setLength(180.0f);
        dolFinRightBack.setType(ArcType.ROUND);
        dolFinRightBack.setFill(Color.web("000000"));

        rotateTransition = new RotateTransition(Duration.millis(1), dolFinRightBack);
        rotateTransition.setByAngle(50f);
        rotateTransition.play();

        Arc dolFinRight1_1 = new Arc();
        dolFinRight1_1.setCenterX(175.0f);
        dolFinRight1_1.setCenterY(207.0f);
        dolFinRight1_1.setRadiusX(30.0f);
        dolFinRight1_1.setRadiusY(15.0f);
        dolFinRight1_1.setStartAngle(180.0f);
        dolFinRight1_1.setLength(180.0f);
        dolFinRight1_1.setType(ArcType.ROUND);
        dolFinRight1_1.setFill(Color.web("4286f4"));

        rotateTransition = new RotateTransition(Duration.millis(1), dolFinRight1_1);
        rotateTransition.setByAngle(65f);
        rotateTransition.play();

        Arc dolFinRight1_1Back = new Arc();
        dolFinRight1_1Back.setCenterX(175.0f);
        dolFinRight1_1Back.setCenterY(207.0f);
        dolFinRight1_1Back.setRadiusX(31.0f);
        dolFinRight1_1Back.setRadiusY(16.0f);
        dolFinRight1_1Back.setStartAngle(180.0f);
        dolFinRight1_1Back.setLength(180.0f);
        dolFinRight1_1Back.setType(ArcType.ROUND);
        dolFinRight1_1Back.setFill(Color.web("000000"));

        rotateTransition = new RotateTransition(Duration.millis(1), dolFinRight1_1Back);
        rotateTransition.setByAngle(65f);
        rotateTransition.play();

        CubicCurve dolFinRight2 = new CubicCurve();
        dolFinRight2.setStartX(140);
        dolFinRight2.setStartY(205);
        dolFinRight2.setControlX1(160);
        dolFinRight2.setControlY1(215);
        dolFinRight2.setControlX2(150);
        dolFinRight2.setControlY2(215);
        dolFinRight2.setEndX(160);
        dolFinRight2.setEndY(240);
        dolFinRight2.setStroke(Color.web("000000"));
        dolFinRight2.setStrokeWidth(1);
        dolFinRight2.setStrokeLineCap(StrokeLineCap.ROUND);
        dolFinRight2.setFill(Color.web("50C21B").deriveColor(0, 0, 0, 0));

        CubicCurve dolFinRight2_1 = new CubicCurve();
        dolFinRight2_1.setStartX(120);
        dolFinRight2_1.setStartY(210);
        dolFinRight2_1.setControlX1(120);
        dolFinRight2_1.setControlY1(215);
        dolFinRight2_1.setControlX2(120);
        dolFinRight2_1.setControlY2(235);
        dolFinRight2_1.setEndX(160);
        dolFinRight2_1.setEndY(240);
        dolFinRight2_1.setStroke(Color.web("000000"));
        dolFinRight2_1.setStrokeWidth(1);
        dolFinRight2_1.setStrokeLineCap(StrokeLineCap.ROUND);
        dolFinRight2_1.setFill(Color.web("50C21B").deriveColor(0, 0, 0, 0));

        //---------------------------------------------------------------------------------------------



        root.getChildren().addAll(
                dolFinRight1_1Back,
                dolFinRight1_1,
                dolFinRightBack,
                dolFinRight1,
                dolTail2Back,
                dolTail1Back,
                dolBody1Back,
                dolBody2Back,
                dolFinBack,
                dolHead,
                dolEyes2,
                dolEyes2_2,
                dolBody1,
                dolBody2,
                dolMouth,
                dolNose,
                dolNose2,
                dolFin,
                dolTail1,
                dolTail2,
                dolEyes1,
                dolEyes1_2,
                dolSpot1,
                dolSpot2,
                dolSpot3,
                dolFinRight2,
                dolFinRight2_1
                );

        // Створення ефекту переміщення
        TranslateTransition translateTransition = new TranslateTransition(Duration.millis(3000), root);
        translateTransition.setFromX(50);
        translateTransition.setToX(500);
        translateTransition.setToY(200);
        translateTransition.setCycleCount(1);
        translateTransition.setAutoReverse(true);
        // Створення повороту об'єкту
        RotateTransition rotateTransition2 = new RotateTransition(Duration.millis(3000), root);
        rotateTransition2.setByAngle(360f);
        rotateTransition2.setCycleCount(1);
        rotateTransition2.setAutoReverse(true);
        // Масштабування об'єкту
        ScaleTransition scaleTransition = new ScaleTransition(Duration.millis(1700), root);
        scaleTransition.setToX(2f);
        scaleTransition.setToY(2f);
        scaleTransition.setCycleCount(2);
        scaleTransition.setAutoReverse(true);

        ParallelTransition parallelTransition = new ParallelTransition();
        parallelTransition.getChildren().addAll(
                rotateTransition2,
                translateTransition,
                scaleTransition
        );
        parallelTransition.play();

        scene.setFill(Color.WHITE);
        primaryStage.setScene(scene);
        primaryStage.show();

    }
}