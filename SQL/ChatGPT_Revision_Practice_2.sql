CREATE DATABASE LibraryDB;
SET SQL_SAFE_UPDATES=0;
USE LibraryDB;
CREATE TABLE Books(
BookID INT PRIMARY KEY,
Title VARCHAR(100),
Author VARCHAR(50),
Price INT,
Genre VARCHAR(30),
PublisherEmail VARCHAR(50));
INSERT INTO Books (BookID,Title,Author,Price,Genre,PublisherEmail)
VALUES
(1,'Atomic Habits','James Clear',499,'Self Help','atomic@penguin.com'),
(2,'The Alchemist','Paulo Coelho',350,'Fiction',NULL),
(3,'Deep Work','Cal Newport',550,'Productivity','cal@grandpub.com'),
(4,'Clean Code','Robert C. Martin',750,'Programming','clean@pearson.com'),
(5,'The Pragmatic Programmer','Andy Hunt',800,'Programming',NULL);
UPDATE Books
SET Price=400
WHERE Title='The Alchemist';
ALTER TABLE Books ADD Column Rating FLOAT;
UPDATE Books
SET Rating=4.8
WHERE Title='Atomic Habits';
UPDATE Books
SET Rating=4.6
WHERE Title='Deep Work';
UPDATE Books
SET Rating=4.9
WHERE Title='Clean Code';
UPDATE Books
SET Rating=4.4
WHERE BookID IN (2,5);
SELECT * FROM Books;
SELECT * FROM Books WHERE Price>500;
SELECT * FROM Books WHERE Genre LIKE '%gram%';
SELECT * FROM Books WHERE PublisherEmail IS NULL;
SELECT * FROM Books WHERE Price	BETWEEN 400 and 800;
SELECT * FROM Books WHERE Title LIKE '%e';
DELETE FROM Books WHERE BookID=5;
-- AGGREGATE fUNCTIONS
SELECT
	MIN(Price) AS Cheapest_Book,
    MAX(Price) AS Costliest_Book,
    AVG(Price) AS Average_Price,
    COUNT(*) AS Total_Books,
    SUM(Price) AS Total_Value,
    STD(Price) AS Standard_Deviation,
    VARIANCE(Price) AS Variance_Book_Price
FROM Books;
-- USING WHERE CLAUSE
SELECT
	MIN(Price) AS Cheapest_Book_Programming,
    MAX(Price) AS Costliest_Book_Programming,
	COUNT(*) AS Total_Books_Programming
FROM Books
WHERE Genre="Programming";
-- USING GROUP BY CLAUSE
SELECT
	MIN(Price) AS Cheapest_Book,
    MAX(Price) AS Costliest_Book,
    AVG(Price) AS Average_Price,
	COUNT(*) AS Total_Books
FROM Books
GROUP BY Genre;
-- HAVING CLAUSE CAN ALSO BE ADDED
SELECT
	MIN(Price) AS Cheapest_Book,
    MAX(Price) AS Costliest_Book,
    AVG(Price) AS Average_Price,
	COUNT(*) AS Total_Books
FROM Books
GROUP BY Genre
HAVING AVG (Price)>500;
-- MODIFYING THE TABLE
INSERT INTO Books (BookID,Title,Author,Price,Genre,PublisherEmail)
VALUES
(6,'Think Like a Monk','Jay Shetty',349,'Self Help','jayshetty@gmail.com');
USE LibraryDB;
CREATE TABLE Authors(
AuthorID INT PRIMARY KEY,
Author VARCHAR(50));
INSERT INTO Authors (AuthorID,Author)
VALUES
(1,'James Clear'),(2,'Paulo Coelho'),(3,'Cal Newport'),(4,'Robert C. Martin'),(5,'Andy Hunt'),(6,'Jay Shetty');
SELECT * FROM Authors;
CREATE TABLE Reviews (
  ReviewID INT PRIMARY KEY,
  BookID INT,
  Rating FLOAT,
  Reviewer VARCHAR(50),
  FOREIGN KEY (BookID) REFERENCES Books(BookID)
);

INSERT INTO Reviews (ReviewID, BookID, Rating, Reviewer)
VALUES
(1, 1, 5.0, 'Rohan'),
(2, 1, 4.7, 'Aditi'),
(3, 2, 4.5, 'Sonal'),
(4, 4, 4.9, 'Riya'),
(5, 6, 4.2, 'Karan');
SELECT * FROM Reviews;
SELECT Title FROM Books b WHERE EXISTS (SELECT * FROM Reviews r WHERE r.BookID=b.BookID);
SELECT Price FROM Books b WHERE b.Price > ANY(SELECT Price FROM Books WHERE Genre='Programming');
SELECT Price FROM Books b WHERE b.Price > ALL(SELECT Price FROM Books WHERE Genre='Programming');
-- JOINING 
-- INNER JOIN: OVERLAPPING AND SHOWING COLUMNS THAT MATCH
SELECT Books.Title, Authors.Author FROM Books INNER JOIN Authors ON Books.Author=Authors.Author;
-- NATURAL JOIN 
SELECT * FROM Books NATURAL JOIN Authors;
-- LEFT AND RIGHT OUTER JOIN
SELECT * FROM Books LEFT OUTER JOIN Authors ON Books.Author=Authors.Author;
SELECT * FROM Books RIGHT OUTER JOIN Authors ON Books.Author=Authors.Author;
-- UNION OF BOTH GIVES A FULLY OUTER JOIN.
SELECT * FROM Books CROSS JOIN Authors;
-- 6*6=36 ROWS POSSIBLE THROUGH ABOVE COMMAND
SELECT b1.Price as CheaperPrice, b2.Price as ExpensivePrice, c1.Book as CheaperBook, c2.Book as ExpensiveBook FROM Books b1 JOIN Books b2 ON b1.Price>b2.Price;