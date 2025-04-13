package dao;

import beans.Seminar;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;

public class SeminarDao {

    private JdbcTemplate template;

    public void setTemplate(JdbcTemplate template) {
        this.template = template;
    }

    public int save(Seminar seminar) {
        String sql = "INSERT INTO seminars (title, description, speaker, date) VALUES (?, ?, ?, ?)";
        return template.update(sql, seminar.getTitle(), seminar.getDescription(), seminar.getSpeaker(), seminar.getDate());
    }

    public int update(Seminar seminar) {
        String sql = "UPDATE seminars SET title=?, description=?, speaker=?, date=? WHERE id=?";
        return template.update(sql, seminar.getTitle(), seminar.getDescription(), seminar.getSpeaker(), seminar.getDate(), seminar.getId());
    }

    public int delete(int id) {
        String sql = "DELETE FROM seminars WHERE id=?";
        return template.update(sql, id);
    }

    public Seminar getSeminarById(int id) {
        String sql = "SELECT * FROM seminars WHERE id=?";
        return template.queryForObject(sql, new Object[]{id}, new BeanPropertyRowMapper<>(Seminar.class));
    }

    public List<Seminar> getAllSeminars() {
        String sql = "SELECT * FROM seminars";
        return template.query(sql, new RowMapper<Seminar>() {
            @Override
            public Seminar mapRow(ResultSet rs, int rowNum) throws SQLException {
                Seminar seminar = new Seminar();
                seminar.setId(rs.getInt("id"));
                seminar.setTitle(rs.getString("title"));
                seminar.setDescription(rs.getString("description"));
                seminar.setSpeaker(rs.getString("speaker"));
                seminar.setDate(rs.getString("date"));
                return seminar;
            }
        });
    }
}
