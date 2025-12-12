CREATE DATABASE StudentPortal;
USE StudentPortal;
CREATE TABLE Students(
    RollNo INT PRIMARY KEY,
    Name VARCHAR(50),
    Age INT,
    Course VARCHAR (50),
    Email VARCHAR(100),
    Grade CHAR(1)
);
INSERT INTO Students (RollNo, Name, Age, Course, Email, Grade)
VALUES (
        1,
        'Abhay',
        19,
        'Chemical Engineering',
        'odysseusnitw753@gmail.com',
        'A'
    ),
    (
        2,
        'Anshuman',
        20,
        'Chemical Engineering',
        'as23chb0a03@student.nitw.ac.in',
        'B'
    ),
    (3, 'Riya', 18, 'Computer Science', NULL, 'A'),
    (4, 'Aarav', 21, 'Mechanical Engineering', NULL, 'C'),
    (
        5,
        'Meera',
        19,
        'Chemical Engineering',
        'meera_ce@nitw.ac.in',
        'B'
    );
-- Manipulation Commands
SET SQL_SAFE_UPDATES = 0;
UPDATE Students
SET Email = 'riya_cs@nitw.ac.in'
WHERE Name = 'Riya';
ALTER TABLE Students
ADD Column City VARCHAR(50);
UPDATE Students
SET City = 'Jeypore'
WHERE RollNo in (1, 2, 3);
UPDATE Students
SET City = 'Warangal'
WHERE RollNo in (4, 5);
SAVEPOINT Step1;
DELETE FROM Students
WHERE RollNo = 4;
SAVEPOINT Step2;
TRUNCATE TABLE Students;
-- Will Not Rollback
ROLLBACK TO Step1;
-- DCL PRACTICE
SELECT *
FROM Students
WHERE Age > 19;
SELECT *
FROM Students
WHERE Course LIKE '%Eng%';
SELECT *
FROM Students
WHERE Name LIKE '%a';
SELECT *
FROM Students
WHERE Age BETWEEN 18 AND 20;
SELECT *
FROM Students
WHERE Email IS NULL;
SELECT *
FROM Students
WHERE Email IS NOT NULL;
SET SQL_SAFE_UPDATES = 1;
COMMIT;
-- GIVE THE RATING OF THE QUERY AND THE FINAL PROGRESS.