package application;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;
import java.io.IOException;

public class main_view_controller {

	
    @FXML
    private TextField ent_book_title;

    @FXML
    private Text rez_author;

    @FXML
    private Text rez_title;

    @FXML
    private TextField search_title_field; // This is the search field for the book search module

    private SampleController sampleController;
    private display_book_controller displayController;
    private BookSearchController bookSearchController; // Add a reference to the BookSearchController
    private edit_book_controller editBookController; // Add a reference to the EditBookController
    private delete_book_controller deleteBookController;
    private Main mainApp;

    public void setMainApp(Main mainApp) {
        this.mainApp = mainApp;
    }

    @FXML
    void load_book(ActionEvent event) {
        loadWindow("/application/Sample.fxml", "Book Window");
    }

    @FXML
    void load_book_table(ActionEvent event) {
        loadWindow("/application/display_book.fxml", "Book Search Window");
        if (displayController != null) {
            displayController.setSampleController(sampleController);
        }
    }

    @FXML
    void load_edit_book(ActionEvent event) {
        loadWindow("/application/edit_book.fxml", "Edit Book");
        if (editBookController != null) {
            editBookController.setSampleController(sampleController);
        }
    }




    @FXML
    void load_search_view(ActionEvent event) {
        loadWindow("/application/bookSearch.fxml", "Book Search Window");
        if (bookSearchController != null) {
            bookSearchController.initialize(); // Initialize the BookSearchController
        }
    }

    @FXML
    void load_delete_search(ActionEvent event) {
        loadWindow("/application/delete_book.fxml", "Delete Book");
        if (deleteBookController != null) {
            deleteBookController.setSampleController(sampleController);
        }
    }
    
    

    @FXML
    void handleNewAction() {
        // Handle New action
        showAlert("Info", "New action selected.");
    }

    @FXML
    void handleOpenAction() {
        // Handle Open action
        showAlert("Info", "Open action selected.");
    }

    @FXML
    void handleSaveAction() {
        // Handle Save action
        showAlert("Info", "Save action selected.");
    }

    @FXML
    void handleSaveAsAction() {
        // Handle Save As action
        showAlert("Info", "Save As action selected.");
    }

    @FXML
    void handleExitAction() {
        // Handle Exit action
        System.exit(0);
    }

    @FXML
    void handleAddBookAction() {
        // Handle Add Book action
        loadWindow("/application/Sample.fxml", "Book Window");
    }

    @FXML
    void handleEditBookAction() {
        // Handle Edit Book action
        loadWindow("/application/edit_book.fxml", "Edit Book");
        if (editBookController != null) {
            editBookController.setSampleController(sampleController);
        }
    }

    @FXML
    void handleDeleteBookAction() {
        // Handle Delete Book action
        loadWindow("/application/delete_book.fxml", "Delete Book");
        if (deleteBookController != null) {
            deleteBookController.setSampleController(sampleController);
        }
    }

    @FXML
    void handleViewAllBooksAction() {
        // Handle View All Books action
        loadWindow("/application/display_book.fxml", "Book Search Window");
        if (displayController != null) {
            displayController.setSampleController(sampleController);
        }
    }

    @FXML
    void handleSearchBooksAction() {
        // Handle Search Books action
        loadWindow("/application/bookSearch.fxml", "Book Search Window");
        if (bookSearchController != null) {
            bookSearchController.initialize();
        }
    }

    private void loadWindow(String loc, String title) {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource(loc));
            Parent parent = loader.load();
            Stage stage = new Stage();
            stage.setTitle(title);
            stage.setScene(new Scene(parent));
            stage.show();

            if (loc.equals("/application/Sample.fxml")) {
                sampleController = loader.getController();
                sampleController.setDisplayController(displayController);
            } else if (loc.equals("/application/display_book.fxml")) {
                displayController = loader.getController();
                displayController.setSampleController(sampleController);
                sampleController.setDisplayController(displayController);
            } else if (loc.equals("/application/bookSearch.fxml")) {
                bookSearchController = loader.getController();
            } else if (loc.equals("/application/edit_book.fxml")) {
                editBookController = loader.getController();
            } else if (loc.equals("/application/delete_book.fxml")) {
                deleteBookController = loader.getController();
            }
        } catch (IOException e) {
            e.printStackTrace();
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error");
            alert.setHeaderText(null);
            alert.setContentText("Failed to load " + title);
            alert.showAndWait();
        }
    }


    @FXML
    void load_issue(ActionEvent event) {
        String bookTitle = ent_book_title.getText();

        if (bookTitle.isEmpty()) {
            showAlert("Error", "Please enter a book title.");
            return;
        }

        Book foundBook = sampleController.searchBook(bookTitle);

        if (foundBook != null) {
            rez_title.setText(foundBook.getTitle());
            rez_author.setText(foundBook.getAuthor());
        } else {
            showAlert("Error", "Book not found.");
        }
    }

    public void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }
}
