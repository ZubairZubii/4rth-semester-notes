package application;

import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.layout.BorderPane;
import javafx.scene.control.*;
import javafx.geometry.Insets;
import javafx.collections.ObservableList;


public class I222591_Q1_DOB_BY_comboBox_COURSE_BY_List extends Application {

	
	 public void start(Stage primaryStage) {
	        primaryStage.setTitle("Student Registration Form - Date by ComboBox, Courses by ListView");

	        TextField nameField = new TextField();
	        nameField.setPromptText("Full Name");

	        ComboBox dayComboBox = new ComboBox();
	        dayComboBox.setPromptText("Day");
	        for (int i = 1; i <= 31; i++) {
	            dayComboBox.getItems().add(i);
	        }

	        ComboBox monthComboBox = new ComboBox();
	        
	        monthComboBox.setPromptText("Month");
	        monthComboBox.getItems().addAll(
	                "January", "February", "March", "April", "May", "June",
	                "July", "August", "September", "October", "November", "December"
	        );

	        ComboBox yearComboBox = new ComboBox();
	        
	        yearComboBox.setPromptText("Year");
	        for (int i = 1900; i <= 2024; i++) {
	            yearComboBox.getItems().add(i);
	        }

	        ToggleGroup genderGroup = new ToggleGroup();
	        RadioButton maleRadioButton = new RadioButton("Male");
	        maleRadioButton.setToggleGroup(genderGroup);
	        RadioButton femaleRadioButton = new RadioButton("Female");
	        femaleRadioButton.setToggleGroup(genderGroup);

	        TextField emailField = new TextField();
	        emailField.setPromptText("Email Address");

	        TextField contactField = new TextField();
	        contactField.setPromptText("Contact Number");

	        TextArea addressArea = new TextArea();
	        addressArea.setPromptText("Address");

	        ListView courseListView = new ListView();
	        courseListView.getItems().addAll("Course 1", "Course 2", "Course 3");
	        courseListView.getSelectionModel().setSelectionMode(SelectionMode.MULTIPLE);

	        Button submitButton = new Button("Submit");

	        VBox root = new VBox(10);
	        root.setPadding(new Insets(10));
	        root.getChildren().addAll(
	                new Label("Student Registration Form - Date by ComboBox, Courses by ListView"),
	                nameField,
	                new Label("Date of Birth"),
	                new HBox(10, dayComboBox, monthComboBox, yearComboBox),
	                new Label("Gender"),
	                new HBox(10, maleRadioButton, femaleRadioButton),
	                emailField,
	                contactField,
	                addressArea,
	                new Label("Choose Course"),
	                courseListView,
	                submitButton
	        );

	        Button exitButton = new Button("Exit");
	        exitButton.setOnAction(e -> primaryStage.close());

	        Button clearButton = new Button("Clear");
	        clearButton.setOnAction(event -> {
	            // Clear form fields
	            nameField.clear();
	            dayComboBox.setValue(null);
	            monthComboBox.setValue(null);
	            yearComboBox.setValue(null);
	            genderGroup.selectToggle(null);
	            emailField.clear();
	            contactField.clear();
	            addressArea.clear();
	            courseListView.getSelectionModel().clearSelection();
	        });
	            
	            Menu file = new Menu("File");
	            MenuItem clearMenuItem = new MenuItem("Clear");
	            
	            clearMenuItem.setOnAction(e -> clearButton.fire());
	            MenuItem exitMenuItem = new MenuItem("Exit");
	            
	            exitMenuItem.setOnAction(e -> exitButton.fire());

	            
	            file.getItems().addAll(clearMenuItem, exitMenuItem);
	            MenuBar menu = new MenuBar(file);
	            
	            VBox mainbox = new VBox(10,menu,root);
	            
	            
	            
	            
	        submitButton.setOnAction(event -> {
	        	 String dob = getDateOfBirth(dayComboBox, monthComboBox, yearComboBox);
	        	    ObservableList selectedCourses = courseListView.getSelectionModel().getSelectedItems();
	        	    
	        	    String errorMessage = validateForm(nameField.getText(), 
	        	                                        dob != null ? dob : null,
	        	                                        emailField.getText(), 
	        	                                        contactField.getText(), 
	        	                                        addressArea.getText(),
	        	                                        selectedCourses != null ? selectedCourses : null);
	            if (errorMessage != null) {
	                showAlert("Validation Error", errorMessage);
	                return;
	            }

	            Alert alert = new Alert(Alert.AlertType.INFORMATION);
	            
	            alert.setTitle("Registration Successful");
	            alert.setHeaderText(null);
	            alert.setContentText("Registration successful!\n\nName: " + nameField.getText() +
	                    "\nDate of Birth: " + getDateOfBirth(dayComboBox, monthComboBox, yearComboBox) +
	                    "\nGender: " + ((RadioButton) genderGroup.getSelectedToggle()).getText() +
	                    "\nEmail: " + emailField.getText() +
	                    "\nContact: " + contactField.getText() +
	                    "\nAddress: " + addressArea.getText() +
	                    "\nCourses: " + (courseListView.getSelectionModel().getSelectedItems()));
	            alert.showAndWait();
	        });

	        
	        Scene scene = new Scene(mainbox, 500, 600);
	        primaryStage.setScene(scene);
	        primaryStage.show();
	    }

	    public void showAlert(String title, String message) {
	        Alert alert = new Alert(Alert.AlertType.ERROR);
	        alert.setTitle(title);
	        alert.setContentText(message);
	        alert.showAndWait();
	    }

	    public String validateForm(String name, String dob, String email, String contact, String address, ObservableList selectedCourses) {
	        if (name.isEmpty()) {
	            return "Name field is empty.";
	        }
	        if (dob == null) {
	            return "Date of Birth field is empty.";
	        }
	        if (email.isEmpty()) {
	            return "Email field is empty.";
	        }
	        if (contact.isEmpty()) {
	            return "Contact Number field is empty.";
	        }
	        if (address.isEmpty()) {
	            return "Address field is empty.";
	        }
	        if ( selectedCourses == null) {
	            return "Course field is empty.";
	        }
	        return null;
	    }

	    public String getDateOfBirth(ComboBox dayComboBox, ComboBox monthComboBox, ComboBox yearComboBox) {
	        Object dayValue = dayComboBox.getValue();
	        Object monthValue = monthComboBox.getValue();
	        Object yearValue = yearComboBox.getValue();

	        if (dayValue != null && monthValue != null && yearValue != null) {
	            return dayValue.toString() + " " + monthValue.toString() + " " + yearValue.toString();
	        } else {
	            return null;
	        }
	    }


	                
	                
	                
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		launch(args);
	}

}
