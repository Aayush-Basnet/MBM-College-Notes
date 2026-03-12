-- Lab 5: Temporal Database. Version Records of a Table



-- Create Temporal Table
CREATE TABLE Student5(
rollno INT,
name VARCHAR(50),
address VARCHAR(50),
contactno VARCHAR(10),

SysStartTime DATETIME2 GENERATED ALWAYS AS ROW START,
SysEndTime DATETIME2 GENERATED ALWAYS AS ROW END,
PERIOD FOR SYSTEM_TIME (SysStartTime, SysEndTime)
)
WITH (SYSTEM_VERSIONING = ON (HISTORY_TABLE = dbo.Student5History));

-- Insert Record
INSERT INTO Student5 (rollno,name,address,contactno)
VALUES (1,'Hari','KTM','1234');

SELECT * FROM Student5;

-- Update Record
UPDATE Student5
SET name = 'Ram'
WHERE rollno = 1;

UPDATE Student5
SET name = 'Mohan'
WHERE rollno = 1;

UPDATE Student5
SET name = 'Geeta'
WHERE rollno = 1;


-- View Current Data
SELECT * FROM Student5;

-- View Version History (Temporal Query)
SELECT *
FROM Student5
FOR SYSTEM_TIME ALL
WHERE rollno = 1;


-- Show Start and End Time
SELECT 
rollno,
name,
SysStartTime AS START_DATE,
SysEndTime AS END_DATE
FROM Student5
FOR SYSTEM_TIME ALL
WHERE rollno = 1;

-- View History table
SELECT * FROM Student5History;