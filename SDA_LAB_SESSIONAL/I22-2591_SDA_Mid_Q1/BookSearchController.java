package application;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.text.Text;

import java.util.ArrayList;

public class BookSearchController {

    @FXML
    private TableView<Book> SearchbookTable;

    @FXML
    private TableColumn<Book, String> authorColumn;

    @FXML
    private TableColumn<Book, String> availabilityColumn;

    @FXML
    private TableColumn<Book, String> isbnColumn;

    @FXML
    private TableColumn<Book, String> titleColumn;

    @FXML
    private Text rez_author;

    @FXML
    private Text rez_availability;

    @FXML
    private Text rez_isbn;

    @FXML
    private Text rez_title;

    @FXML
    private TextField search_title_field;

    private ObservableList<Book> bookList = FXCollections.observableArrayList();

    @FXML
    public void initialize() {
        // Initialize TableView columns
        titleColumn.setCellValueFactory(cellData -> cellData.getValue().titleProperty());
        authorColumn.setCellValueFactory(cellData -> cellData.getValue().authorProperty());
        isbnColumn.setCellValueFactory(cellData -> cellData.getValue().isbnProperty());
        availabilityColumn.setCellValueFactory(cellData -> cellData.getValue().availabilityProperty());

        // Populate TableView with sample data (you should replace this with your actual book data)
        bookList.addAll(SampleController.getBooks());
        SearchbookTable.setItems(bookList);
        
        // Enable sorting for each column
        titleColumn.setSortType(TableColumn.SortType.ASCENDING);
        SearchbookTable.getSortOrder().add(titleColumn);

        titleColumn.setSortable(true);
        authorColumn.setSortable(true);
        isbnColumn.setSortable(true);

        SearchbookTable.sort();  // Initial sorting based on title
    }

    @FXML
    void load_search_book(ActionEvent event) {
        String searchTitle = search_title_field.getText();

        if (searchTitle.isEmpty()) {
            showAlert("Error", "Please enter a book title to search.");
            return;
        }

        Book foundBook = searchBook(searchTitle);

        if (foundBook != null) {
            rez_title.setText(foundBook.getTitle());
            rez_author.setText(foundBook.getAuthor());
            rez_isbn.setText(foundBook.getIsbn());
            rez_availability.setText(foundBook.getAvailability());
        } else {
            showAlert("Error", "Book not found.");
        }
    }

    @FXML
    void selectBook(MouseEvent event) {
        Book selectedBook = SearchbookTable.getSelectionModel().getSelectedItem();

        if (selectedBook != null) {
            rez_title.setText(selectedBook.getTitle());
            rez_author.setText(selectedBook.getAuthor());
            rez_isbn.setText(selectedBook.getIsbn());
            rez_availability.setText(selectedBook.getAvailability());
        }
    }

    private Book searchBook(String title) {
        for (Book book : bookList) {
            if (book.getTitle().equalsIgnoreCase(title)) {
                return book;
            }
        }
        return null;  // Book not found
    }

    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }
}
