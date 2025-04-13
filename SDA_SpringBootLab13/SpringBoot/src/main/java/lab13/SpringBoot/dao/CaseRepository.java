package lab13.SpringBoot.dao;

import org.springframework.data.jpa.repository.JpaRepository;

import lab13.SpringBoot.entity.Case;

public interface CaseRepository extends JpaRepository<Case, Integer> {
}
