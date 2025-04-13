package lab13.SpringBootcontroller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import lab13.SpringBoot.entity.Case;
import lab13.SpringBoot.service.CaseService;

@RestController
@RequestMapping("/cases")
public class CaseController {

    @Autowired
    private CaseService caseService;

    @GetMapping("/{id}")
    public Case getCaseById(@PathVariable Integer id) {
        return caseService.findById(id);
    }

    @PostMapping
    public Case createCase(@RequestBody Case newCase) {
        return caseService.save(newCase);
    }

    @PutMapping("/{id}")
    public Case updateCase(@PathVariable Integer id, @RequestBody Case updatedCase) {
        return caseService.updateCase(id, updatedCase);
    }

    @DeleteMapping("/{id}")
    public void deleteCase(@PathVariable Integer id) {
        caseService.deleteById(id);
    }
}
