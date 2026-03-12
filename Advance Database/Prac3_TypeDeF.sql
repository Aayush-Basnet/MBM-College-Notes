-- Case 1- Create Address Table

CREATE TABLE Address2 (
    address_id INT IDENTITY(1,1) PRIMARY KEY,
    street VARCHAR(60),
    city VARCHAR(30),
    state CHAR(2),
    zip_code CHAR(5)
);

-- Insert Address
INSERT INTO Address2 (street, city, state, zip_code)
VALUES ('Sanepa','Lalitpur','BG','LAL');

SELECT * FROM Address2;

-- Case 2: Create Person Table
CREATE TABLE Person2 (
    person_id INT IDENTITY(1,1) PRIMARY KEY,
    name VARCHAR(30),
    ssn INT,
    address_id INT,
    FOREIGN KEY (address_id) REFERENCES Address2(address_id)
);

-- Insert Person
INSERT INTO Person2 (name, ssn, address_id)
VALUES ('Ram',123456,1);

SELECT * FROM Person2;


-- Employee Table
CREATE TABLE Employees2 (
    empnumber INT PRIMARY KEY,
    person_id INT,
    manager_id INT,
    office_address_id INT,
    salary DECIMAL(10,2),
    FOREIGN KEY (person_id) REFERENCES Person2(person_id),
    FOREIGN KEY (manager_id) REFERENCES Person2(person_id),
    FOREIGN KEY (office_address_id) REFERENCES Address2(address_id)
);

-- Insert Employee
INSERT INTO Employees2 (empnumber, person_id, salary)
VALUES (1,1,50000);

SELECT * FROM Address2;


-- Phone Numbers Table
CREATE TABLE Phone_Array (
    phone_id INT IDENTITY(1,1) PRIMARY KEY,
    empnumber INT,
    phone_number VARCHAR(30),
    FOREIGN KEY (empnumber) REFERENCES Employees2(empnumber)
);

-- Insert Phone Numbers
INSERT INTO Phone_Array (empnumber, phone_number)
VALUES
(1,'1'),(1,'2'),(1,'3'),(1,'4'),(1,'5');

SELECT * FROM Address2;

-- Multiple Address Table
CREATE TABLE Employee_Address (
    id INT IDENTITY(1,1) PRIMARY KEY,
    empnumber INT,
    address_id INT,
    FOREIGN KEY (empnumber) REFERENCES Employees2(empnumber),
    FOREIGN KEY (address_id) REFERENCES Address2(address_id)
);

-- Insert Multiple Addresses
INSERT INTO Employee_Address (empnumber, address_id)
VALUES (1,1);

SELECT * FROM Person2;

SELECT * FROM Employees2;

SELECT * FROM Phone_Array;

SELECT * FROM Employee_Address;