SHOW DATABASES;
USE collegedb;
SHOW TABLES;
DESC Students; -- Describe the structure of the table
SELECT * FROM Students; -- View Entire Table
SELECT * FROM Students WHERE Age=20;
SELECT Name,RollNo FROM Students;
SELECT * FROM Students WHERE Age=20 AND Name='Alok Kumar'; -- No Values found
-- Altering Values in the Table
ALTER TABLE Students ADD COLUMN Email VARCHAR(100); -- Adds New Column Email to the table

-- THE BELOW CODE WILL SHOW AN INSERTION DEFAULT VALUE ERROR AS MYSQL EXPECTS YOU TO SUPPLY ALL THE VALUES
-- INSERT INTO Students (Email) -- Use this only when you have fully new rows to insert.
-- VALUES('odysseusnitw753@gmail.com'),
-- ('as23chb0a03@student.nitw.ac.in'),
-- ('Iska_mereko_nii_maalum');
-- SELECT * FROM Students;

UPDATE Students SET Email='odysseusnitw753@gmail.com' WHERE RollNo=1;
UPDATE Students SET Email='as23chb0a03@student.nitw.ac.in' WHERE RollNo=2;
UPDATE Students SET Email='Iska_mereko_nii_maalum' WHERE RollNo=3;
SELECT * FROM Students;

INSERT INTO Students (RollNo, Name, Age, Course, Email)
VALUES (4,'Anshuman Parida',22,'Chemical Engineering','ap23chb0b05@student.nitw.ac.in');
SELECT * FROM Students;

DELETE FROM Students WHERE RollNo=4;
SELECT * FROM Students;
