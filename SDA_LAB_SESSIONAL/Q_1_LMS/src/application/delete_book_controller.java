package application;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.*;
public class delete_book_controller {

    @FXML
    private Button cancelButton;

    @FXML
    private Button deleteButton;

    @FXML
    private TextField delete_author_field;

    @FXML
    private TextField delete_availability_field;

    @FXML
    private TextField delete_isbn_field;

    @FXML
    private AnchorPane delete_root_page;

    @FXML
    private TextField delete_title_field;

    private SampleController sampleController;

    public void setSampleController(SampleController sampleController) {
        this.sampleController = sampleController;
    }

    @FXML
    void cancel_delete(ActionEvent event) {
        closeWindow();
    }

    @FXML
    void delete_book(ActionEvent event) {
        String bookTitle = delete_title_field.getText().trim();

        if (bookTitle.isEmpty()) {
            showAlert("Error", "Please enter a book title.");
            return;
        }

        Book bookToDelete = sampleController.searchBook(bookTitle);

        if (bookToDelete != null) {
            sampleController.deleteBook(bookToDelete);
            sampleController.updateTableView();
            closeWindow();
            showAlert("Success", "Book deleted successfully.");
        } else {
            showAlert("Error", "Book not found.");
        }
    }

    private void closeWindow() {
        delete_title_field.getScene().getWindow().hide();
    }

    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }
}
