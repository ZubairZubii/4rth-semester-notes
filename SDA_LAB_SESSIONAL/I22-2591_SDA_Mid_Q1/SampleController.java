package application;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import javafx.stage.*;
import java.util.ArrayList;

public class SampleController {

    @FXML
    private TextField author;

    @FXML
    private TextField available;

    @FXML
    private TextField isbn;

    @FXML
    private TextField title;

    @FXML
    private AnchorPane rootpage;
    private static ArrayList<Book> books = new ArrayList<>();  // Static list
    private display_book_controller displayController;

    @FXML
    void cancelbook(ActionEvent event) {
        closeWindow();
    }

    public void addBook(Book book) {
        books.add(book);
    }
    
    private boolean isValidISBN(String isbn) {
        // Check if the ISBN is 13 digits long
        if (isbn.length() != 13) {
            return false;
        }
        
        // Check if all characters in the ISBN are digits
        for (char c : isbn.toCharArray()) {
            if (!Character.isDigit(c)) {
                return false;
            }
        }
        
        return true;
    }

    
    @FXML
    void savebook(ActionEvent event) {
        String bookTitle = title.getText();
        String bookAuthor = author.getText();
        String bookIsbn = isbn.getText();
        String bookAvailable = available.getText();

        if (bookTitle.isEmpty() || bookAuthor.isEmpty() || bookIsbn.isEmpty() || bookAvailable.isEmpty()) {
            showAlert("Error", "All fields are required.");
            return;
        }

        // Validation for ISBN format
        if (!isValidISBN(bookIsbn)) {
            showAlert("Error", "Invalid ISBN format.");
            return;
        }

        
        Book book = new Book(bookTitle, bookAuthor, bookIsbn, bookAvailable);
        addBook(book);  // Add book to the list

        System.out.println("All Books:");
        for (Book b : books) {
            System.out.println(b.toString());
        }

        showAlert("Success", "Book added successfully.");

        clearFields();

        if (displayController != null) {
            displayController.updateTableView();
        } else {
            System.out.println("displayController is null. Cannot update TableView.");
        }
    }

    private void clearFields() {
        title.clear();
        author.clear();
        isbn.clear();
        available.clear();
    }

    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }

    public static ArrayList<Book> getBooks() {
        return books;
    }

    public void setDisplayController(display_book_controller displayController) {
        this.displayController = displayController;
    }

    private void closeWindow() {
        Stage stage = (Stage) rootpage.getScene().getWindow();
        stage.close();
    }
    
    public Book searchBook(String title) {
        for (Book book : books) {
            if (book.getTitle().equalsIgnoreCase(title)) {
                return book;
            }
        }
        return null;  // Book not found
    }
    


 // Inside SampleController class
    public void updateTableView() {
        if (displayController != null) {
            displayController.updateTableView(); // Update the display
        } else {
            System.out.println("displayController is null. Cannot update TableView.");
        }
    }
 // Inside SampleController class

    public void deleteBook(Book bookToDelete) {
        books.remove(bookToDelete);
    }


}
