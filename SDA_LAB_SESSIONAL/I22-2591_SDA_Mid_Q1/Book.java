package application;

import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class Book {
    private final StringProperty title;
    private final StringProperty author;
    private final StringProperty isbn;
    private final StringProperty availability;

    public Book(String title, String author, String isbn, String availability) {
        this.title = new SimpleStringProperty(title);
        this.author = new SimpleStringProperty(author);
        this.isbn = new SimpleStringProperty(isbn);
        this.availability = new SimpleStringProperty(availability);
    }

    // Getters for properties

    public String getTitle() {
        return title.get();
    }

    public String getAuthor() {
        return author.get();
    }

    public String getIsbn() {
        return isbn.get();
    }

    public String getAvailability() {
        return availability.get();
    }

    // Property getters

    public StringProperty titleProperty() {
        return title;
    }

    public StringProperty authorProperty() {
        return author;
    }

    public StringProperty isbnProperty() {
        return isbn;
    }

    public StringProperty availabilityProperty() {
        return availability;
    }

    // Setters (optional, if needed)

    public void setTitle(String title) {
        this.title.set(title);
    }

    public void setAuthor(String author) {
        this.author.set(author);
    }

    public void setIsbn(String isbn) {
        this.isbn.set(isbn);
    }

    public void setAvailability(String availability) {
        this.availability.set(availability);
    }

    
    @Override
    public String toString() {
        return "Book{" +
                "title='" + title.get() + '\'' +
                ", author='" + author.get() + '\'' +
                ", isbn='" + isbn.get() + '\'' +
                ", availability='" + availability.get() + '\'' +
                '}';
    }
}
