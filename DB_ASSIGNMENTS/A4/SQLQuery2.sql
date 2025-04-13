
CREATE TABLE Admin (
    AdminID INT PRIMARY KEY,
    Name VARCHAR(255) NOT NULL,
    Email VARCHAR(255) UNIQUE NOT NULL
);


CREATE TABLE College (
    CollegeID INT PRIMARY KEY ,
    Name VARCHAR(255),
    Address VARCHAR(255),
    ContactNumber VARCHAR(20),
    EstablishedDate DATE,
	AdminID INT
	FOREIGN KEY (AdminID) REFERENCES Admin(AdminID) ON DELETE SET NULL
);


CREATE TABLE CollegeStaff (
    StaffID INT PRIMARY KEY,
    Name VARCHAR(255),
    Email VARCHAR(255) UNIQUE,
    Role VARCHAR(255),
    CollegeID INT,
    FOREIGN KEY (CollegeID) REFERENCES College(CollegeID) ON DELETE SET NULL
);


CREATE TABLE Department (
    DepartmentID INT PRIMARY KEY,
    Name VARCHAR(255),
    CollegeID INT,
    HOD VARCHAR(255),
    OfficeNumber VARCHAR(20),
    FOREIGN KEY (CollegeID) REFERENCES College(CollegeID)
);


CREATE TABLE Program (
    ProgramID INT PRIMARY KEY,
    Name VARCHAR(255),
    Description TEXT,
    TotalCredits INT CHECK (TotalCredits > 0),
    DepartmentID INT  ,
	CollegeStaffID INT,
    FOREIGN KEY (DepartmentID) REFERENCES Department(DepartmentID),
	FOREIGN KEY (CollegeStaffID) REFERENCES CollegeStaff(StaffID) ON DELETE SET NULL
);


CREATE TABLE UndergraduateProgram (
    ProgramID INT PRIMARY KEY,
    Duration INT,
    Major VARCHAR(255),
    FOREIGN KEY (ProgramID) REFERENCES Program(ProgramID)
);


CREATE TABLE PostgraduateProgram (
    ProgramID INT PRIMARY KEY,
    Duration INT,
    Specialization VARCHAR(255),
    FOREIGN KEY (ProgramID) REFERENCES Program(ProgramID)
);


CREATE TABLE DiplomaProgram (
    ProgramID INT PRIMARY KEY,
    Duration INT,
    Field VARCHAR(255),
    FOREIGN KEY (ProgramID) REFERENCES Program(ProgramID)
);

CREATE TABLE Course (
    CourseID INT PRIMARY KEY,
    Name VARCHAR(255),
    Description TEXT,
    Credits INT CHECK (Credits > 0),
    DepartmentID INT,
    Semester VARCHAR(50),
    FOREIGN KEY (DepartmentID) REFERENCES Department(DepartmentID)
);


CREATE TABLE CoreCourse (
    CourseID INT PRIMARY KEY,
    Prerequisites TEXT,
    CoreCredits INT,
    FOREIGN KEY (CourseID) REFERENCES Course(CourseID)
);


CREATE TABLE ElectiveCourse (
    CourseID INT PRIMARY KEY,
    ElectiveCredits INT,
    FOREIGN KEY (CourseID) REFERENCES Course(CourseID)
);


CREATE TABLE Person (
    PersonID INT PRIMARY KEY,
    Name VARCHAR(255),
    Email VARCHAR(255) UNIQUE,
    DateOfBirth DATE ,
    Type VARCHAR(50)
);

CREATE TABLE Student (
    StudentID INT PRIMARY KEY,
    AdmissionDate DATE,
    Batch VARCHAR(50),
    FOREIGN KEY (StudentID) REFERENCES Person(PersonID)
);


CREATE TABLE Faculty (
    FacultyID INT PRIMARY KEY,
    DateOfJoining DATE CHECK (DateOfJoining <= GETDATE()),
    Qualification VARCHAR(255),
    FOREIGN KEY (FacultyID) REFERENCES Person(PersonID)
);


CREATE TABLE Enrollment (
    EnrollmentID INT PRIMARY KEY,
    StudentID INT,
    CourseID INT,
    EnrollmentDate DATE CHECK (EnrollmentDate <= GETDATE()),
    Status VARCHAR(50) CHECK (Status IN ('Active', 'Completed', 'Dropped')),
    Timeslot VARCHAR(50),
	CollegeStaffID INT,
    FOREIGN KEY (StudentID) REFERENCES Student(StudentID) ON DELETE set NULL,
    FOREIGN KEY (CourseID) REFERENCES Course(CourseID) ON DELETE set NULL,
	FOREIGN KEY (CollegeStaffID) REFERENCES CollegeStaff(StaffID) ON DELETE SET NULL
);



CREATE TABLE FacultyAssignment (
    AssignmentID INT PRIMARY KEY,
    FacultyID INT,
    DepartmentID INT,
    CourseID INT,
    StartDate DATE,
    EndDate DATE,
    RecurringType VARCHAR(50) CHECK (RecurringType IN ('daily', 'weekly', 'monthly')),
    DaysOfWeek VARCHAR(50),
    Timeslot VARCHAR(50),
    FOREIGN KEY (FacultyID) REFERENCES Faculty(FacultyID) ON DELETE set NULL,
    FOREIGN KEY (DepartmentID) REFERENCES Department(DepartmentID) ON DELETE set NULL,
    FOREIGN KEY (CourseID) REFERENCES Course(CourseID) ON DELETE set NULL,
    CHECK (StartDate <= EndDate)
);


CREATE TABLE Roles (
    RoleID INT PRIMARY KEY,
    RoleName VARCHAR(255)
);


CREATE TABLE Users (
    UserID INT PRIMARY KEY,
    Username VARCHAR(255),
    Email VARCHAR(255),
    RoleID INT,
    CollegeID INT,
    FOREIGN KEY (RoleID) REFERENCES Roles(RoleID) ON DELETE SET NULL,
    FOREIGN KEY (CollegeID) REFERENCES College(CollegeID) ON DELETE SET NULL
);




CREATE TABLE Credential (
    CredentialID INT PRIMARY KEY,
    Password VARCHAR(255) UNIQUE NOT NULL,
    AdminID INT,
    UserID INT,
    FOREIGN KEY (AdminID) REFERENCES Admin(AdminID) ON DELETE SET  NULL,
    FOREIGN KEY (UserID) REFERENCES Users(UserID) ON DELETE SET NULL
);


CREATE TABLE AdminDashboard (
    DashboardID INT PRIMARY KEY,
    AdminID INT,
    Insights TEXT,
    Statistic TEXT,
    FOREIGN KEY (AdminID) REFERENCES Admin(AdminID) ON DELETE SET NULL
);








--INSERTIONS


INSERT INTO College (CollegeID, Name, Address, ContactNumber, EstablishedDate)
VALUES
(1, 'Pakistan Institute of Technology', 'Islamabad', '+92-51-1234567', '1990-01-01'),
(2, 'Lahore University', 'Lahore', '+92-42-7654321', '1985-05-05'),
(3, 'Karachi College of Arts', 'Karachi', '+92-21-9876543', '1995-10-10'),
(4, 'Quetta Engineering College', 'Quetta', '+92-81-1122334', '2000-03-15'),
(5, 'Peshawar Medical University', 'Peshawar', '+92-91-5566778', '1980-12-20'),
(6, 'Multan Business School', 'Multan', '+92-61-3344556', '1992-08-18'),
(7, 'Rawalpindi Science College', 'Rawalpindi', '+92-51-4433221', '1975-04-25'),
(8, 'Faisalabad Agriculture University', 'Faisalabad', '+92-41-7788990', '1988-07-30'),
(9, 'Hyderabad Law College', 'Hyderabad', '+92-22-1122334', '1997-06-12'),
(10, 'Sialkot Fashion School', 'Sialkot', '+92-52-9988776', '2005-09-05');



INSERT INTO CollegeStaff (StaffID, Name, Email, Role, CollegeID)
VALUES
(1, 'Ali Ahmed', 'ali.ahmed@example.com', 'Administrator', 1),
(2, 'Sana Khan', 'sana.khan@example.com', 'Admission Officer', 2),
(3, 'Murtaza Hussain', 'murtaza.hussain@example.com', 'Registrar', 3),
(4, 'Fatima Aziz', 'fatima.aziz@example.com', 'Faculty Coordinator', 4),
(5, 'Kamran Malik', 'kamran.malik@example.com', 'Accountant', 5),
(6, 'Ayesha Qureshi', 'ayesha.qureshi@example.com', 'Librarian', 6),
(7, 'Imran Shah', 'imran.shah@example.com', 'HR Manager', 7),
(8, 'Zainab Aslam', 'zainab.aslam@example.com', 'IT Manager', 8),
(9, 'Usman Haider', 'usman.haider@example.com', 'Counselor', 9),
(10, 'Sadia Naveed', 'sadia.naveed@example.com', 'Sports Coordinator', 10);


INSERT INTO Department (DepartmentID, Name, CollegeID, HOD, OfficeNumber)
VALUES
(1, 'Computer Science', 1, 'Dr. Ahmed Raza', 'CS-101'),
(2, 'Electrical Engineering', 1, 'Dr. Saima Khan', 'EE-201'),
(3, 'Business Administration', 2, 'Dr. Ali Abbas', 'BA-301'),
(4, 'Fine Arts', 3, 'Prof. Asma Zia', 'FA-401'),
(5, 'Civil Engineering', 4, 'Dr. Ahsan Ali', 'CE-501'),
(6, 'Medicine', 5, 'Dr. Farah Khan', 'Med-601'),
(7, 'Commerce', 6, 'Prof. Imran Haider', 'CO-701'),
(8, 'Science', 7, 'Dr. Samina Iqbal', 'SC-801'),
(9, 'Law', 8, 'Barrister Saad Malik', 'LW-901'),
(10, 'Fashion Design', 9, 'Ms. Sara Amin', 'FD-1001');


INSERT INTO Program (ProgramID, Name, Description, TotalCredits, DepartmentID, CollegeStaffID)
VALUES
(1, 'Bachelor in Computer Science', '4-year program', 130, 1, 1),
(2, 'Master in Electrical Engineering', '2-year program', 30, 2, 2),
(3, 'MBA', '2-year program', 72, 3, 3),
(4, 'BFA', '4-year program', 140, 4, 4),
(5, 'Bachelor in Civil Engineering', '4-year program', 130, 5, 5),
(6, 'MBBS', '5-year program', 200, 6, 6),
(7, 'BBA', '4-year program', 130, 7, 7),
(8, 'BS in Chemistry', '4-year program', 130, 8, 8),
(9, 'LLB', '5-year program', 150, 9, 9),
(10, 'Fashion Designing', '2-year program', 60, 10, 10);



INSERT INTO UndergraduateProgram (ProgramID, Duration, Major)
VALUES
(1, 4, 'Computer Science'),
(5, 4, 'Civil Engineering'),
(7, 4, 'Business Administration'),
(10, 2, 'Fashion Design');


INSERT INTO PostgraduateProgram (ProgramID, Duration, Specialization)
VALUES
(2, 2, 'Power Systems'),
(3, 2, 'Finance'),
(8, 2, 'Organic Chemistry'),
(9, 2, 'Corporate Law');


INSERT INTO DiplomaProgram (ProgramID, Duration, Field)
VALUES
(4, 2, 'Fine Arts'),
(6, 2, 'Medicine');


INSERT INTO Course (CourseID, Name, Description, Credits, DepartmentID, Semester)
VALUES
(1, 'Data Structures', 'Advanced data structure topics', 4, 1, 'Spring'),
(2, 'Digital Logic Design', 'Basic digital logic principles', 3, 1, 'Fall'),
(3, 'Financial Accounting', 'Basic accounting principles', 3, 3, 'Spring'),
(4, 'Oil Painting', 'Introduction to oil painting techniques', 3, 4, 'Fall'),
(5, 'Structural Analysis', 'Basic structural principles', 4, 5, 'Spring'),
(6, 'Anatomy', 'Study of human body structure', 4, 6, 'Fall'),
(7, 'Marketing Management', 'Marketing principles', 3, 7, 'Spring'),
(8, 'Organic Chemistry', 'Basic principles of organic chemistry', 4, 8, 'Fall'),
(9, 'Criminal Law', 'Basic principles of criminal law', 3, 9, 'Spring'),
(10, 'Fashion Illustration', 'Fashion design illustration techniques', 3, 10, 'Fall');

INSERT INTO Course (CourseID, Name, Description, Credits, DepartmentID, Semester)
VALUES
(11, 'Fashion Illustration', 'Fashion design illustration techniques', 3, 1, 'Fall');

ALTER TABLE Course
ADD CreatedDate DATE;



INSERT INTO CoreCourse (CourseID, Prerequisites, CoreCredits)
VALUES
(1, 'Introduction to Programming', 2),
(5, 'Basic Mechanics', 3),
(7, 'Principles of Management', 2),
(8, 'General Chemistry', 3),
(9, 'Constitutional Law', 2);


INSERT INTO ElectiveCourse (CourseID, ElectiveCredits)
VALUES
(2, 1),
(3, 1),
(4, 2),
(6, 1),
(10, 2);


INSERT INTO Person (PersonID, Name, Email, DateOfBirth, Type)
VALUES
(1, 'Ahmed Ali', 'ahmed.ali@example.com', '1995-02-15', 'Student'),
(2, 'Sana Kamal', 'sana.kamal@example.com', '1990-06-10', 'Student'),
(3, 'Murtaza Shah', 'murtaza.shah@example.com', '1985-08-20', 'Faculty'),
(4, 'Fatima Asif', 'fatima.asif@example.com', '1980-12-05', 'Faculty'),
(5, 'Kamran Rehman', 'kamran.rehman@example.com', '1993-05-25', 'Student'),
(6, 'Ayesha Qasim', 'ayesha.qasim@example.com', '1992-11-30', 'Faculty'),
(7, 'Imran Iqbal', 'imran.iqbal@example.com', '1994-03-10', 'Student'),
(8, 'Zainab Yousaf', 'zainab.yousaf@example.com', '1991-07-15', 'Student'),
(9, 'Usman Riaz', 'usman.riaz@example.com', '1987-04-20', 'Faculty'),
(10, 'Sadia Rashid', 'sadia.rashid@example.com', '1996-09-05', 'Student');


INSERT INTO Student (StudentID, AdmissionDate, Batch)
VALUES
(1, '2020-09-01', 'BSCS-2016'),
(2, '2018-08-15', 'BS-2015'),
(5, '2021-01-10', 'BSCS-2020'),
(7, '2019-07-05', 'BBA-2017'),
(8, '2017-05-20', 'BS-2014'),
(10, '2022-02-10', 'BFA-2021');


INSERT INTO Faculty (FacultyID, DateOfJoining, Qualification)
VALUES
(3, '2010-01-15', 'Ph.D. in Computer Science'),
(4, '2005-07-10', 'Masters in Fine Arts'),
(6, '2015-03-20', 'MBBS, FCPS'),
(9, '2008-06-25', 'LLM');


INSERT INTO Faculty (FacultyID, DateOfJoining, Qualification)
VALUES
(5, '2017-09-05', 'Ph.D. in Physics'),
(7, '2016-02-10', 'Masters in History'),
(8, '2018-11-15', 'Ph.D. in Literature'),
(10, '2019-04-20', 'MBA');


INSERT INTO Enrollment (EnrollmentID, StudentID, CourseID, EnrollmentDate, Status, Timeslot, CollegeStaffID)
VALUES
(1, 1, 1, '2020-09-10', 'Active', 'Morning', 2),
(2, 2, 3, '2018-08-20', 'Completed', 'Evening', 2),
(3, 5, 5, '2021-01-15', 'Active', 'Morning', 4),
(4, 7, 7, '2019-07-10', 'Completed', 'Evening', 4),
(5, 8, 8, '2017-05-25', 'Active', 'Morning', 5),
(6, 10, 10, '2022-02-15', 'Active', 'Evening', 7);


INSERT INTO FacultyAssignment (AssignmentID, FacultyID, DepartmentID, CourseID, StartDate, EndDate, RecurringType, DaysOfWeek, Timeslot)
VALUES
(1, 3, 1, 1, '2020-09-01', '2022-09-01', 'weekly', 'Monday', 'Morning'),
(2, 4, 4, 4, '2019-09-01', '2021-09-01', 'weekly', 'Wednesday', 'Evening'),
(3, 6, 6, 6, '2020-01-01', '2025-01-01', 'monthly', 'First', 'Morning'),
(4, 9, 9, 9, '2018-01-01', '2023-01-01', 'daily', '', 'Evening');


INSERT INTO FacultyAssignment (AssignmentID, FacultyID, DepartmentID, CourseID, StartDate, EndDate, RecurringType, DaysOfWeek, Timeslot)
VALUES
(5, 5, 7, 5, '2021-03-01', '2023-03-01', 'weekly', 'Tuesday', 'Morning'),
(6, 7, 8, 7, '2022-04-01', '2024-04-01', 'monthly', 'Second', 'Evening'),
(7, 8, 10, 8, '2021-06-01', '2023-06-01', 'daily', '', 'Morning'),
(8, 10, 10, 10, '2022-01-01', '2024-01-01', 'weekly', 'Thursday', 'Evening');


INSERT INTO Roles (RoleID, RoleName)
VALUES
(1, 'Admin'),
(2, 'Faculty'),
(3, 'Student'),
(4, 'Staff');


INSERT INTO Users (UserID, Username, Email, RoleID, CollegeID)
VALUES
(1, 'admin', 'admin@example.com', 1, 1),
(2, 'sana.khan', 'sana.khan@example.com', 4, 2),
(3, 'murtaza.shah', 'murtaza.shah@example.com', 2, 3),
(4, 'fatima.asif', 'fatima.asif@example.com', 2, 4),
(5, 'kamran.rehman', 'kamran.rehman@example.com', 3, 5),
(6, 'ayesha.qasim', 'ayesha.qasim@example.com', 2, 6),
(7, 'imran.iqbal', 'imran.iqbal@example.com', 3, 7),
(8, 'zainab.yousaf', 'zainab.yousaf@example.com', 3, 8),
(9, 'usman.riaz', 'usman.riaz@example.com', 2, 9),
(10, 'sadia.rashid', 'sadia.rashid@example.com', 3, 10);


INSERT INTO Admin (AdminID, Name, Email)
VALUES
(1, 'John Doe', 'johndoe@example.com'),
(2, 'Jane Smith', 'janesmith@example.com'),
(3, 'Emily Brown', 'emilybrown@example.com'),
(4, 'Michael Johnson', 'michaeljohnson@example.com'),
(5, 'Sophia Williams', 'sophiawilliams@example.com'),
(6, 'William Jones', 'williamjones@example.com'),
(7, 'Olivia Davis', 'oliviadavis@example.com'),
(8, 'Daniel Miller', 'danielmiller@example.com'),
(9, 'Isabella Wilson', 'isabellawilson@example.com'),
(10, 'Matthew Taylor', 'matthewtaylor@example.com');


INSERT INTO Credential (CredentialID, Password, AdminID, UserID)
VALUES
(1, 'adminpassword1', 1, 1),
(2, 'adminpassword2', 2, 2),
(3, 'adminpassword3', 3, 3),
(4, 'adminpassword4', 4, 4),
(5, 'adminpassword5', 5, 5),
(6, 'adminpassword6', 6, 6),
(7, 'adminpassword7', 7, 7),
(8, 'adminpassword8', 8, 8),
(9, 'adminpassword9', 9, 9),
(10, 'adminpassword10', 10, 10);



INSERT INTO AdminDashboard (DashboardID, AdminID, Insights, Statistic)
VALUES
(1, 1, 'Faculty assignments for the next week', 'Number of courses per department'),
(2, 2, 'Student enrollment trends', 'Course completion rates'),
(3, 3, 'Faculty availability for the current month', 'Student engagement metrics'),
(4, 4, 'Upcoming program deadlines', 'Resource allocation for departments'),
(5, 5, 'Course feedback from students', 'Faculty performance metrics'),
(6, 6, 'Program effectiveness analysis', 'Student dropout rates'),
(7, 7, 'Faculty training needs', 'Department-wise student satisfaction'),
(8, 8, 'Resource allocation overview', 'Course popularity trends'),
(9, 9, 'Student attendance records', 'Faculty workload analysis'),
(10, 10, 'Faculty development programs', 'Student feedback on courses');


SELECT * FROM FACULTY
SELECT * FROM Student
select * from College
select * from Admin
SELECT * FROM Course
Select * from FacultyAssignment
Select * from AdminDashboard
Select * from Credential
Select * from Users
Select * from Roles
Select * from AdminDashboard
Select * from Person
Select * from ElectiveCourse
Select * from CoreCourse
Select * from Program
Select * from DiplomaProgram
Select * from PostgraduateProgram
Select * from UndergraduateProgram
Select * from Department
Select * from CollegeStaff


