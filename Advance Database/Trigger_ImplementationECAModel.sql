

-- Create Transaction Table
CREATE TABLE employee(
empid INT,
empname VARCHAR(50),
address VARCHAR(100),
contactno VARCHAR(10)
);

EXEC sp_help employee;

-- Create Audit Table
CREATE TABLE audit_trail(
empid_val INT,
empname_val VARCHAR(50),
op_date DATETIME,
operation VARCHAR(100)
);

-- Insert Data
INSERT INTO employee 
VALUES (1,'Ram Singh','KTM','12345');


-- View Table
SELECT * FROM employee;

SELECT * FROM audit_trail;


-- Create Trigger (Post Insert Event)
CREATE TRIGGER trig_audittrail
ON employee
AFTER INSERT
AS
BEGIN

INSERT INTO audit_trail(
empid_val,
empname_val,
op_date,
operation
)
SELECT 
empid,
empname,
GETDATE(),
'Record Insertion'
FROM INSERTED;

END;

-- Test Trigger
INSERT INTO employee 
VALUES (2,'Sita','BKT','7678687');

-- Check Audit Trail
SELECT * FROM employee;

SELECT * FROM audit_trail;