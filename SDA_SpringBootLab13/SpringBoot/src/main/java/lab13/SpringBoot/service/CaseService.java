package lab13.SpringBoot.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import lab13.SpringBoot.dao.CaseRepository;
import lab13.SpringBoot.entity.Case;

@Service
public class CaseService {

    @Autowired
    private CaseRepository caseRepository;

    public Case findById(Integer id) {
        return caseRepository.findById(id).orElse(null);
    }

    public Case save(Case newCase) {
        return caseRepository.save(newCase);
    }

    public Case updateCase(Integer id, Case updatedCase) {
        updatedCase.setId(id);
        return caseRepository.save(updatedCase);
    }

    public void deleteById(Integer id) {
        caseRepository.deleteById(id);
    }
}
