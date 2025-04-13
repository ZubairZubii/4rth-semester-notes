



select * from Faculty
select * from Program
select * from Users
select * from Credentials
SELECT * FROM College
select * from Enrollment
select * from Student
Select * from FacultyAssignment
Select * from Course
Select * from Department

select * from ElectiveCourse





UPDATE College
SET Address = 'Multan'
WHERE CollegeID = 5;


UPDATE Department
SET HOD = 'Dr. Jane Smith'
WHERE DepartmentID = 6;



UPDATE FacultyAssignment
SET Timeslot = 'Morning'
WHERE AssignmentID = 4;


UPDATE Enrollment
SET Status = 'Completed'
WHERE EnrollmentID = 7;


UPDATE Program
SET Description = 'Bachelor of Computer Science and Engineering'
WHERE ProgramID = 9;

UPDATE Users
SET RoleID = 4
WHERE UserID = 13;

UPDATE Users
SET Email = 'updatedusman.riaz@example.com'
WHERE UserID = 9;


UPDATE Credentials
SET Password = 'newadminpassword7'
WHERE UserID = 7;


UPDATE Admin
SET Name = 'UpdatedAdmin'
WHERE AdminID = 10;


UPDATE AdminDashboard
SET Insights = 'Updated insights for admin'
WHERE AdminID = 10;




--QUERY1

--DAILY
SELECT 
   Day( E.EnrollmentDate) as Enrollday, 
    P.Name AS StudentName, 
    P.Email AS StudentEmail, 
    S.Batch,
    C.Name AS CollegeName,
    COUNT(E.StudentID) AS Enrollments
FROM Enrollment E
JOIN Student S ON E.StudentID = S.StudentID
JOIN Person P ON S.StudentID = P.PersonID
JOIN College C ON e.CourseID = C.CollegeID
WHERE C.Name = 'Pakistan Institute of Technology'
GROUP BY Day( E.EnrollmentDate), P.Name, P.Email, S.Batch, C.Name
ORDER BY Enrollday;

--WEEKLY
SELECT 
    DATEPART(WEEK, E.EnrollmentDate) AS EnrollmentWeek,
    P.Name AS StudentName,
    P.Email AS StudentEmail,
    S.Batch,
    COUNT(E.StudentID) AS Enrollments
FROM Enrollment E
JOIN Student S ON E.StudentID = S.StudentID
JOIN Person P ON S.StudentID = P.PersonID
JOIN College C ON E.CourseID = C.CollegeID
WHERE C.Name = 'Pakistan Institute of Technology'
GROUP BY DATEPART(WEEK, E.EnrollmentDate), P.Name, P.Email, S.Batch
ORDER BY EnrollmentWeek, StudentName;

--MONTHLY
SELECT 
    DATEPART(MONTH, E.EnrollmentDate) AS EnrollmentMonth,
    P.Name AS StudentName,
    P.Email AS StudentEmail,
    S.Batch,
    COUNT(E.StudentID) AS Enrollments
FROM Enrollment E
JOIN Student S ON E.StudentID = S.StudentID
JOIN Person P ON S.StudentID = P.PersonID
JOIN College C ON E.CourseID = C.CollegeID
WHERE C.Name = 'Pakistan Institute of Technology'
GROUP BY DATEPART(MONTH, E.EnrollmentDate), P.Name, P.Email, S.Batch
ORDER BY EnrollmentMonth, StudentName;






--QUERY2

--DAILY
SELECT 
   DAY(C.CreatedDate) AS CreatedDay,
    D.Name AS DepartmentName,
    C.Name AS CourseName,
    C.Credits
FROM Course C
JOIN Department D ON C.DepartmentID = D.DepartmentID
WHERE D.Name = 'Computer Science'
GROUP BY  DAY(C.CreatedDate), D.Name, C.Name, C.Credits
ORDER BY CreatedDay, DepartmentName, CourseName;

--WEEKLY
SELECT 
DATEPART(WEEK, C.CreatedDate) AS CourseWeek,
D.Name AS DepartmentName,
	     C.Name AS CourseName,
		 CA.EstablishedDate,
		 CA.Name AS College_name
	FROM Course C
JOIN Department D ON C.DepartmentID = D.DepartmentID
JOIN College CA ON D.CollegeID = CA.CollegeID
WHERE D.Name = 'Computer Science'
GROUP BY DATEPART(WEEK, C.CreatedDate), D.Name , C.Name ,CA.EstablishedDate,CA.Name
ORDER BY CourseWeek, DepartmentName, CourseName;

--MONTHLY
SELECT 
    DATEPART(MONTH, C.CreatedDate) AS CourseMonth,
    D.Name AS DepartmentName,
    C.Name AS CourseName,
    C.Credits,
	 CA.Name AS College_name
FROM Course C
JOIN Department D ON C.DepartmentID = D.DepartmentID
JOIN College CA ON D.CollegeID = CA.CollegeID
WHERE D.Name = 'Computer Science'
GROUP BY DATEPART(MONTH, C.CreatedDate), D.Name, C.Name, C.Credits, CA.Name
ORDER BY CourseMonth, DepartmentName, CourseName;





--Query3

--DAILY
SELECT 
    DAY(E.EnrollmentDate) as Enroll_Day,
    P.Name AS StudentName,
    C.Name AS CourseName,
    S.Batch,
	C.Name as  Course_Name
FROM Enrollment E
JOIN Student S ON E.StudentID = S.StudentID
JOIN Person P ON S.StudentID = P.PersonID
JOIN Course C ON E.CourseID = C.CourseID
WHERE C.Name = 'Data Structures'
GROUP BY DAY(E.EnrollmentDate), P.Name, C.Name, S.Batch, C.Name
ORDER BY Enroll_Day, StudentName, CourseName;


--WEEKLY
SELECT 
    DATEPART(WEEK, E.EnrollmentDate) AS EnrollmentWeek,
    P.Name AS StudentName,
    C.Name AS CourseName,
    S.Batch,
	C.Name as Course_Name
FROM Enrollment E
JOIN Student S ON E.StudentID = S.StudentID
JOIN Person P ON S.StudentID = P.PersonID
JOIN Course C ON E.CourseID = C.CourseID
WHERE C.Name = 'Data Structures' 
GROUP BY DATEPART(WEEK, E.EnrollmentDate), P.Name, C.Name, S.Batch,C.Name
ORDER BY EnrollmentWeek, StudentName, CourseName;

--MONTHLY
SELECT 
    MONTH(E.EnrollmentDate) AS EnrollmentMonth,
    P.Name AS StudentName,
    C.Name AS CourseName,
    S.Batch,
	C.Name as Course_Name
FROM Enrollment E
JOIN Student S ON E.StudentID = S.StudentID
JOIN Person P ON S.StudentID = P.PersonID
JOIN Course C ON E.CourseID = C.CourseID
WHERE C.Name = 'Data Structures' 
GROUP BY MONTH(E.EnrollmentDate), P.Name, C.Name, S.Batch,C.Name
ORDER BY EnrollmentMonth, StudentName, CourseName;





--Quey4
SELECT pe.Name AS Faculty, c.Name AS Course, fa.StartDate, fa.EndDate
FROM FacultyAssignment fa
JOIN Faculty f ON fa.FacultyID = f.FacultyID
JOIN Course c ON fa.CourseID = c.CourseID
JOIN Person pe ON f.FacultyID = pe.PersonID
WHERE fa.StartDate BETWEEN '2018-01-01' AND '2020-01-01';


--Query5

--Weekly
SELECT 
    FA1.FacultyID,
    p.Name AS FacultyName,
    D1.Name AS Department1,
    D2.Name AS Department2,
    FA1.CourseID AS CourseID1,
    FA2.CourseID AS CourseID2,
    FA1.StartDate AS StartDate1,
    FA1.EndDate AS EndDate1,
    FA2.StartDate AS StartDate2,
    FA2.EndDate AS EndDate2,
	 DATEPART(WEEK, FA1.StartDate) AS WEEK1 ,
	 DATEPART(WEEK, FA2.StartDate) AS WEEK2
FROM FacultyAssignment FA1
JOIN FacultyAssignment FA2 ON FA1.FacultyID = FA2.FacultyID
JOIN Faculty F ON FA1.FacultyID = F.FacultyID
Join Person p ON p.PersonID = F.FacultyID
JOIN Department D1 ON FA1.DepartmentID = D1.DepartmentID
JOIN Department D2 ON FA2.DepartmentID = D2.DepartmentID
WHERE FA1.StartDate <= FA2.EndDate AND FA1.EndDate >= FA2.StartDate AND FA1.AssignmentID != FA2.AssignmentID
AND DATEPART(WEEK, FA1.StartDate) = DATEPART(WEEK, FA2.StartDate);


--Daily
SELECT 
    FA1.FacultyID,
    p.Name AS FacultyName,
    D1.Name AS Department1,
    D2.Name AS Department2,
    FA1.CourseID AS CourseID1,
    FA2.CourseID AS CourseID2,
    FA1.StartDate AS StartDate1,
    FA1.EndDate AS EndDate1,
    FA2.StartDate AS StartDate2,
    FA2.EndDate AS EndDate2,
	DAY(FA1.StartDate) AS DAY1,
	DAY(FA2.StartDate) DAY2
FROM FacultyAssignment FA1
JOIN FacultyAssignment FA2 ON FA1.FacultyID = FA2.FacultyID
JOIN Faculty F ON FA1.FacultyID = F.FacultyID
Join Person p ON p.PersonID = F.FacultyID
JOIN Department D1 ON FA1.DepartmentID = D1.DepartmentID
JOIN Department D2 ON FA2.DepartmentID = D2.DepartmentID
WHERE FA1.StartDate <= FA2.EndDate AND FA1.EndDate >= FA2.StartDate AND FA1.AssignmentID != FA2.AssignmentID
AND DAY(FA1.StartDate) = DAY(FA2.StartDate);


--Monthly
SELECT 
    FA1.FacultyID,
    p.Name AS FacultyName,
    D1.Name AS Department1,
    D2.Name AS Department2,
    FA1.CourseID AS CourseID1,
    FA2.CourseID AS CourseID2,
    FA1.StartDate AS StartDate1,
    FA1.EndDate AS EndDate1,
    FA2.StartDate AS StartDate2,
    FA2.EndDate AS EndDate2,
	DATEPART(MONTH, FA1.StartDate) AS Month1,
	DATEPART(MONTH, FA2.StartDate) AS Month2
FROM FacultyAssignment FA1
JOIN FacultyAssignment FA2 ON FA1.FacultyID = FA2.FacultyID
JOIN Faculty F ON FA1.FacultyID = F.FacultyID
Join Person p ON p.PersonID = F.FacultyID
JOIN Department D1 ON FA1.DepartmentID = D1.DepartmentID
JOIN Department D2 ON FA2.DepartmentID = D2.DepartmentID
WHERE FA1.StartDate <= FA2.EndDate AND FA1.EndDate >= FA2.StartDate AND FA1.AssignmentID != FA2.AssignmentID
AND DATEPART(MONTH, FA1.StartDate) = DATEPART(MONTH, FA2.StartDate);


--QUERY6

--Weekly
SELECT 
    FA.FacultyID,
    p.Name AS FacultyName,
    D.Name AS DepartmentName,
    COUNT(FA.AssignmentID) AS AssignmentCount,
    DATEPART(WEEK, FA.StartDate) AS AssignWeek
FROM FacultyAssignment FA
JOIN Department D ON FA.DepartmentID = D.DepartmentID
JOIN Faculty F ON FA.FacultyID = F.FacultyID
JOIN Person p ON p.PersonID = F.FacultyID
where D.Name =  'Computer Science'
GROUP BY FA.FacultyID, p.Name, D.Name, DATEPART(WEEK, FA.StartDate)
HAVING COUNT(FA.AssignmentID) = (
    SELECT MIN(AssignmentCount)
    FROM (
        SELECT COUNT(FA.AssignmentID) AS AssignmentCount
        FROM FacultyAssignment FA
		JOIN Department D ON FA.DepartmentID = D.DepartmentID
		where D.Name =  'Computer Science'
        GROUP BY FacultyID, DATEPART(WEEK, StartDate)
    ) AS Subquery
)
ORDER BY AssignmentCount;

--Monthly
SELECT 
    FA.FacultyID,
    p.Name AS FacultyName,
    D.Name AS DepartmentName,
    COUNT(FA.AssignmentID) AS AssignmentCount,
    DATEPART(MONTH, FA.StartDate) AS AssignMonth
FROM FacultyAssignment FA
JOIN Department D ON FA.DepartmentID = D.DepartmentID
JOIN Faculty F ON FA.FacultyID = F.FacultyID
JOIN Person p ON p.PersonID = F.FacultyID
where D.Name =  'Computer Science'
GROUP BY FA.FacultyID, p.Name, D.Name, DATEPART(MONTH, FA.StartDate)
HAVING COUNT(FA.AssignmentID) = (
    SELECT MIN(AssignmentCount)
    FROM (
        SELECT COUNT(FA.AssignmentID) AS AssignmentCount
        FROM FacultyAssignment FA
		JOIN Department D ON FA.DepartmentID = D.DepartmentID
		where D.Name =  'Computer Science'
        GROUP BY FacultyID, DATEPART(MONTH, StartDate)
    ) AS Subquery
)
ORDER BY AssignmentCount;

--Daily
SELECT 
    FA.FacultyID,
    p.Name AS FacultyName,
    D.Name AS DepartmentName,
    COUNT(FA.AssignmentID) AS AssignmentCount,
     DAY(FA.StartDate) AS AssignDay
FROM FacultyAssignment FA
JOIN Department D ON FA.DepartmentID = D.DepartmentID
JOIN Faculty F ON FA.FacultyID = F.FacultyID
JOIN Person p ON p.PersonID = F.FacultyID
where D.Name =  'Computer Science'
GROUP BY FA.FacultyID, p.Name, D.Name, DAY(FA.StartDate)
HAVING COUNT(FA.AssignmentID) = (
    SELECT MIN(AssignmentCount)
    FROM (
        SELECT COUNT(FA.AssignmentID) AS AssignmentCount
        FROM FacultyAssignment FA
		JOIN Department D ON FA.DepartmentID = D.DepartmentID
		where D.Name =  'Computer Science'
        GROUP BY FacultyID,  DAY(FA.StartDate)
    ) AS Subquery
)
ORDER BY AssignmentCount;



--Query7

--Weekly
SELECT 
    FA.FacultyID,
    p.Name AS FacultyName,
    D.Name AS DepartmentName,
    COUNT(FA.AssignmentID) AS AssignmentCount,
    DATEPART(WEEK, FA.StartDate) AS AssignWeek
FROM FacultyAssignment FA
JOIN Department D ON FA.DepartmentID = D.DepartmentID
JOIN Faculty F ON FA.FacultyID = F.FacultyID
JOIN Person p ON p.PersonID = F.FacultyID
where D.Name =  'Fashion Design'
GROUP BY FA.FacultyID, p.Name, D.Name, DATEPART(WEEK, FA.StartDate)
HAVING COUNT(FA.AssignmentID) = (
    SELECT MAX(AssignmentCount)
    FROM (
        SELECT COUNT(FA.AssignmentID) AS AssignmentCount
        FROM FacultyAssignment FA
		JOIN Department D ON FA.DepartmentID = D.DepartmentID
		where D.Name =  'Fashion Design'
        GROUP BY FacultyID, DATEPART(WEEK, StartDate)
    ) AS Subquery
)
ORDER BY AssignmentCount;


--Monthly
SELECT 
    FA.FacultyID,
    p.Name AS FacultyName,
    D.Name AS DepartmentName,
    COUNT(FA.AssignmentID) AS AssignmentCount,
    DATEPART(MONTH, FA.StartDate) AS AssignMonth
FROM FacultyAssignment FA
JOIN Department D ON FA.DepartmentID = D.DepartmentID
JOIN Faculty F ON FA.FacultyID = F.FacultyID
JOIN Person p ON p.PersonID = F.FacultyID
where D.Name =  'Fashion Design'
GROUP BY FA.FacultyID, p.Name, D.Name, DATEPART(MONTH, StartDate)
HAVING COUNT(FA.AssignmentID) = (
    SELECT MAX(AssignmentCount)
    FROM (
        SELECT COUNT(FA.AssignmentID) AS AssignmentCount
        FROM FacultyAssignment FA
		JOIN Department D ON FA.DepartmentID = D.DepartmentID
		where D.Name =  'Fashion Design'
        GROUP BY FacultyID, DATEPART(MONTH, StartDate)
    ) AS Subquery
)
ORDER BY AssignmentCount;


--Daily
SELECT 
    FA.FacultyID,
    p.Name AS FacultyName,
    D.Name AS DepartmentName,
    COUNT(FA.AssignmentID) AS AssignmentCount,
    DAY(FA.StartDate) AS AssignDay
FROM FacultyAssignment FA
JOIN Department D ON FA.DepartmentID = D.DepartmentID
JOIN Faculty F ON FA.FacultyID = F.FacultyID
JOIN Person p ON p.PersonID = F.FacultyID
where D.Name =  'Fashion Design'
GROUP BY FA.FacultyID, p.Name, D.Name,  DAY(FA.StartDate)
HAVING COUNT(FA.AssignmentID) = (
    SELECT MAX(AssignmentCount)
    FROM (
        SELECT COUNT(FA.AssignmentID) AS AssignmentCount
        FROM FacultyAssignment FA
		JOIN Department D ON FA.DepartmentID = D.DepartmentID
		where D.Name =  'Fashion Design'
        GROUP BY FacultyID,  DAY(FA.StartDate)
    ) AS Subquery
)
ORDER BY AssignmentCount;



--Query8
SELECT p.Name AS StudentName, c.Name AS Course, COUNT( e.CourseID) AS EnrollmentCount
FROM Enrollment e
JOIN Student s ON e.StudentID = s.StudentID
JOIN Person p ON s.StudentID = p.PersonID
JOIN Course c ON e.CourseID = c.CourseID
GROUP BY p.Name, c.Name
HAVING COUNT( e.CourseID) > 1;


--Query9
SELECT p.Name AS Student,  c.Name AS Course, COUNT(DISTINCT e.CourseID) AS DifferentCoursesEnrolled
FROM Enrollment e
JOIN Student s ON e.StudentID = s.StudentID
JOIN Person p ON s.StudentID = p.PersonID
JOIN Course c ON e.CourseID = c.CourseID
GROUP BY p.Name ,c.Name
HAVING COUNT(DISTINCT e.CourseID) > 1;




-- Retrieve all users with their roles
SELECT u.Username, u.Email, ur.RoleName
FROM Users u
JOIN Roles ur ON ur.RoleID = u.RoleID;


--List all users and their roles within a specific college
SELECT u.Username, r.RoleName, c.Name AS CollegeName
FROM Users u
JOIN Roles r ON u.RoleID = r.RoleID
 JOIN College c ON u.CollegeID = c.CollegeID
WHERE u.CollegeID = 4;


--Retrieve all admins with their respective dashboards:
SELECT a.AdminID, a.Name, a.Email, ad.Insights, ad.Statistic
FROM Admin a
 JOIN AdminDashboard ad ON a.AdminID = ad.AdminID;



 --Retrieve specific Admin and their dashboard details:
 SELECT a.AdminID, a.Name, a.Email, ad.Insights, ad.Statistic
FROM Admin a
JOIN AdminDashboard ad ON a.AdminID = ad.AdminID
WHERE a.AdminID = 1; 
