CREATE DATABASE Advance_Database;


-- Case 1:
CREATE TABLE Advance_Database..Student(
roll_number int,
First_Name varchar(30),
Mid_Name Varchar(30),
Last_Name varchar(30),
Contact_No varchar(10), 
email varchar(40),
DOB date
);

Select * From Advance_Database..Student;

Insert into Advance_Database..Student values
(1,'Ram','','Singh',123456,'', '2002-05-12');

select * from Advance_Database..Student;


-- Case 2:
Create or Replace type personname as object(
First_Name varchar2(30),
Mid_Name Varchar2(30),
Last_Name Varchar2(30));


CREATE TABLE Student2(
    roll INT,
    First_Name VARCHAR(30),
    Mid_Name VARCHAR(30),
    Last_Name VARCHAR(30),
    contact_no VARCHAR(10),
    email VARCHAR(30),
    DOB DATE
);


select * from student2;

INSERT INTO Student2
VALUES (1,'Ram','','Singh','123456','',GETDATE());


-- Case 3:

CREATE FUNCTION getAge (@dob DATE)
RETURNS INT
AS
BEGIN
    RETURN DATEDIFF(YEAR, @dob, GETDATE());
END;

CREATE TABLE Student3(
    roll INT,
    First_Name VARCHAR(30),
    Mid_Name VARCHAR(30),
    Last_Name VARCHAR(30),
    DOB DATE,
    contact_no VARCHAR(10),
    email VARCHAR(100)
);

INSERT INTO Student3
VALUES (1,'Ram','Kumar','Singh','1980-01-01','123456','ram@testmail.com');


SELECT * FROM Student3;

-- Select with Age Calculation
SELECT 
roll,
First_Name,
Mid_Name,
Last_Name,
DOB,
FORMAT(DOB,'dd/MMM/yyyy') AS Formatted_DOB,
contact_no,
email,
dbo.getAge(DOB) AS Age
FROM Student3;


-- Final Output Query
SELECT 
roll,
First_Name,
Mid_Name,
Last_Name,
DOB,
contact_no,
email,
dbo.getAge(DOB) AS Age
FROM Student3;