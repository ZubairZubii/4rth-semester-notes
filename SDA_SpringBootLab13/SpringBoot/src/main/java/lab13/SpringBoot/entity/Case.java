package lab13.SpringBoot.entity;

import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.Table;

import java.util.Date;

@Entity
@Table(name = "cases")
public class Case {

    @Id
    private Integer id;
    private String title;
    private String description;
    private String suspects;
    private Date date;

    public Case() {
        super();
    }

    public Case(Integer id, String title, String description, String suspects, Date date) {
        super();
        this.id = id;
        this.title = title;
        this.description = description;
        this.suspects = suspects;
        this.date = date;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getSuspects() {
        return suspects;
    }

    public void setSuspects(String suspects) {
        this.suspects = suspects;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    @Override
    public String toString() {
        return String.format("Case [id=%s, title=%s, description=%s, suspects=%s, date=%s]", id, title, description, suspects, date);
    }
}
