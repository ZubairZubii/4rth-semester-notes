package application;


import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;

public class Main extends Application {

	@Override
    public void start(Stage primaryStage) {
        try {
            FXMLLoader mainLoader = new FXMLLoader(getClass().getResource("/application/main_view.fxml"));
            StackPane mainRoot = (StackPane) mainLoader.load();

            main_view_controller mainController = mainLoader.getController();
            mainController.setMainApp(this);

            Scene scene = new Scene(mainRoot, 800,600);
            scene.getStylesheets().add(getClass().getResource("/application/application.css").toExternalForm());

            primaryStage.setTitle("Library Management System");
            primaryStage.setScene(scene);
            primaryStage.show();
        } catch(Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        launch(args);
    }
}

