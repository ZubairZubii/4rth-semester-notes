import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class book_servelet extends HttpServlet {
  

    // Define a list of books
    private List<Book> books = new ArrayList<>();

    public book_servelet() {
        // Initialize the list of books
        books.add(new Book("Title1", "Author1", "Genre1", 20.0));
        books.add(new Book("Title2", "Author2", "Genre2", 25.0));
        books.add(new Book("Title3", "Author3", "Genre3", 30.0));
    }
//tr->row
//td-simpledata
//th->data bold and center
    protected void doGet(HttpServletRequest req, HttpServletResponse res)
            throws ServletException, IOException {
        
        res.setContentType("text/html");
        
        res.getWriter().println("<html>");
        res.getWriter().println("<head>");
        res.getWriter().println("<title>Book List</title>");
        res.getWriter().println("<style>");
        res.getWriter().println("table {");
        res.getWriter().println("    width: 70%;");
        res.getWriter().println("    margin-top: 30px;");
        res.getWriter().println("    margin-left: 100px;");
        res.getWriter().println("}");
        res.getWriter().println("th, td {");
        res.getWriter().println("    border: 4 px solid black;");
        res.getWriter().println("    padding: 8px;");
        res.getWriter().println("    text-align: left;");
        res.getWriter().println("    background-color: brown;");
        
        res.getWriter().println("}");
        res.getWriter().println("</style>");
        res.getWriter().println("</head>");
        res.getWriter().println("<body>");
        
        res.getWriter().println("<h1>Book List</h1>");
        
        res.getWriter().println("<table>");
        res.getWriter().println("<tr>");
        res.getWriter().println("<th>Title</th>");
        res.getWriter().println("<th>Author</th>");
        res.getWriter().println("<th>Genre</th>");
        res.getWriter().println("<th>Price</th>");
        res.getWriter().println("</tr>");
        
        for (Book book : books) {
            res.getWriter().println("<tr>");
            res.getWriter().println("<td>" + book.getTitle() + "</td>");
            res.getWriter().println("<td>" + book.getAuthor() + "</td>");
            res.getWriter().println("<td>" + book.getGenre() + "</td>");
            res.getWriter().println("<td>" + book.getPrice() + "</td>");
            res.getWriter().println("</tr>");
        }
        
        res.getWriter().println("</table>");
        
        res.getWriter().println("</body>");
        res.getWriter().println("</html>");
    }


  
    private static class Book {
        private String title;
        private String author;
        private String genre;
        private double price;

        public Book(String title, String author, String genre, double price) {
            this.title = title;
            this.author = author;
            this.genre = genre;
            this.price = price;
        }

        
        public String getTitle() {
            return title;
        }

        public String getAuthor() {
            return author;
        }

        public String getGenre() {
            return genre;
        }

        public double getPrice() {
            return price;
        }
    }
}
