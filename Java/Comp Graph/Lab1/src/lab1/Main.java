package lab1;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.scene.shape.*;


public class Main extends Application{

    public static void main (String args[]) {
        launch(args); // main method
    }

    @Override
    public void start(Stage primaryStage)
    {
        Group root = new Group();
        Scene scene = new Scene(root, 800, 600);
        scene.setFill(Color.rgb(128,128,0));

        addRectangle(root,50, 50, 700, 500, Color.rgb(128,0,0));

        addLine(root, 400, 50, 400, 216, Color.YELLOW);//first v
        addLine(root, 50, 216, 750, 216, Color.YELLOW);//first h
        addLine(root, 225, 216, 225, 382, Color.YELLOW);//second v
        addLine(root, 575, 216, 575, 382, Color.YELLOW);//third v
        addLine(root, 50, 382, 750, 382, Color.YELLOW);//second h
        addLine(root, 400, 382, 400, 550, Color.YELLOW);//fourth v

        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void addRectangle(Group root, double x, double y, double width, double height, Color color) {
        Rectangle rectangle = new Rectangle(x, y, width, height);
        root.getChildren().add(rectangle);
        rectangle.setFill(color);
    }

    private void addLine(Group root, double startX, double startY, double endX, double endY, Color color) {
        Line line = new Line(startX, startY, endX, endY);
        root.getChildren().add(line);
        line.setStroke(color);
    }
}