package controller;

import beans.Seminar;
import dao.SeminarDao;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@Controller
public class SeminarController {

    @Autowired
    private SeminarDao dao;

    @RequestMapping("/seminarForm")
    public String showSeminarForm(Model model) {
        model.addAttribute("command", new Seminar());
        return "seminarform";
    }

    @RequestMapping(value = "/saveSeminar", method = RequestMethod.POST)
    public String saveSeminar(@ModelAttribute("seminar") Seminar seminar) {
        dao.save(seminar);
        return "redirect:/seminars/list";
    }

    @RequestMapping("/seminars/list")
    public String showSeminarList(Model model) {
        List<Seminar> seminars = dao.getAllSeminars();
        model.addAttribute("list", seminars);
        return "viewseminars";
    }

    @RequestMapping(value = "/editseminar/{id}")
    public String showUpdateSeminarForm(@PathVariable int id, Model model) {
        Seminar seminar = dao.getSeminarById(id);
        model.addAttribute("command", seminar);
        return "seminareditform";
    }

    @RequestMapping(value = "/editsave", method = RequestMethod.POST)
    public String updateSeminar(@ModelAttribute("seminar") Seminar seminar) {
        dao.update(seminar);
        return "redirect:/seminars/list";
    }

    @RequestMapping(value = "/deleteseminar/{id}")
    public String deleteSeminar(@PathVariable int id) {
        dao.delete(id);
        return "redirect:/seminars/list";
    }
}
