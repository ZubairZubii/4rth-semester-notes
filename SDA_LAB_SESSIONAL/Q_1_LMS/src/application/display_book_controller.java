package application;

import javafx.fxml.FXML;

import javafx.scene.control.TableColumn;
import javafx.scene.control.TableColumn.SortType;
import javafx.scene.control.TableView;

public class display_book_controller {

    @FXML
    private TableColumn<Book, String> author_col;

    @FXML
    private TableColumn<Book, String> avail_col;

    @FXML
    private TableColumn<Book, String> isbn_col;

    @FXML
    private TableColumn<Book, String> title_col;

    @FXML
    private TableView<Book> view_table;

    private SampleController sampleController;

    public void initialize() {
        title_col.setCellValueFactory(cellData -> cellData.getValue().titleProperty());
        author_col.setCellValueFactory(cellData -> cellData.getValue().authorProperty());
        isbn_col.setCellValueFactory(cellData -> cellData.getValue().isbnProperty());
        avail_col.setCellValueFactory(cellData -> cellData.getValue().availabilityProperty());

        // Enable sorting for each column
        title_col.setSortable(true);
        author_col.setSortable(true);
        isbn_col.setSortable(true);
        avail_col.setSortable(true);

        // Set initial sort order and type
        title_col.setSortType(SortType.ASCENDING);
        view_table.getSortOrder().add(title_col);

        // Update TableView data
        updateTableView();

        
    }

    public void updateTableView() {
        view_table.getItems().clear();
        view_table.getItems().addAll(SampleController.getBooks());
        // Sort the table based on the current sort order
        view_table.sort();
    }

    
    
    public void setSampleController(SampleController sampleController) {
        this.sampleController = sampleController;
        if (sampleController != null) {
            updateTableView(); 
        } else {
            System.out.println("SampleController or its book list is null.");
        }
    }

    
}
