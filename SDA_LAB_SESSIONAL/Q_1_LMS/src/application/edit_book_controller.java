package application;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;

public class edit_book_controller {

    @FXML
    public TextField edit_author_field;

    @FXML
    public TextField edit_availability_field;

    @FXML
    public TextField edit_isbn_field;

    @FXML
    public TextField edit_title_field;

    public SampleController sampleController;

    public void setSampleController(SampleController sampleController) {
        this.sampleController = sampleController;
    }

    @FXML
    void cancel_edit(ActionEvent event) {
        closeWindow();
    }

    @FXML
    void update_book(ActionEvent event) {
        String bookTitle = edit_title_field.getText().trim();
        String bookAuthor = edit_author_field.getText();
        String bookIsbn = edit_isbn_field.getText();
        String bookAvailability = edit_availability_field.getText();

        if (bookTitle.isEmpty() || bookAuthor.isEmpty() || bookIsbn.isEmpty() || bookAvailability.isEmpty()) {
            showAlert("Error", "All fields are required.");
            return;
        }

        Book bookToUpdate = sampleController.searchBook(bookTitle);

        if (bookToUpdate != null) {
            bookToUpdate.setAuthor(bookAuthor);
            bookToUpdate.setIsbn(bookIsbn);
            bookToUpdate.setAvailability(bookAvailability);

            sampleController.updateTableView(); 
            closeWindow();
            showAlert("Success", "Book updated successfully.");
        } else {
            showAlert("Error", "Book not found.");
        }
    }

    private void closeWindow() {
        edit_title_field.getScene().getWindow().hide();
    }

    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }
}
