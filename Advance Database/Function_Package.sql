-- Concept of Function, Procedure, Package and their use 

-- Case 1: Fetch Person Name
CREATE FUNCTION dbo.Fetch_Person_Name (@Emp_ID INT)
RETURNS VARCHAR(120)
AS
BEGIN
    DECLARE @Name VARCHAR(120)

    SELECT @Name =
        ISNULL(First_Name,'') + ' ' +
        ISNULL(Mid_Name,'') + ' ' +
        ISNULL(Last_Name,'')
    FROM dbo.Personnel_Detail
    WHERE Emp_Number = @Emp_ID

    RETURN @Name
END
GO


-- Case 2: Fetch Appointed Unit Code
CREATE FUNCTION dbo.Fetch_Appoint_Unit (@Emp_ID INT)
RETURNS VARCHAR(3)
AS
BEGIN
    DECLARE @Unit VARCHAR(3)

    SELECT @Unit = Appoint_Unit
    FROM dbo.Personnel_Detail
    WHERE Emp_Number = @Emp_ID

    RETURN @Unit
END
GO


-- Case 3: Fetch Appointed Unit Name
CREATE FUNCTION dbo.Appoint_Unit_Name (@Emp_ID INT)
RETURNS VARCHAR(80)
AS
BEGIN
    DECLARE @Unit_Name VARCHAR(80)

    SELECT @Unit_Name = U.Unit_Name
    FROM dbo.Personnel_Detail P
    JOIN dbo.Unit_Master U
        ON P.Appoint_Unit = U.Unit_Code
    WHERE P.Emp_Number = @Emp_ID

    RETURN @Unit_Name
END
GO


-- Case 4: Fetch Appointed Post Code
CREATE FUNCTION dbo.Appoint_Post_Code (@Emp_ID INT)
RETURNS VARCHAR(3)
AS
BEGIN
    DECLARE @Post VARCHAR(3)

    SELECT @Post = Appoint_Post
    FROM dbo.Personnel_Detail
    WHERE Emp_Number = @Emp_ID

    RETURN @Post
END
GO


SELECT dbo.Fetch_Person_Name(101)

SELECT 
    dbo.Fetch_Person_Name(Emp_Number) AS Name,
    dbo.Fetch_Appoint_Unit(Emp_Number) AS Unit,
    dbo.Appoint_Unit_Name(Emp_Number) AS Unit_Name,
    dbo.Appoint_Post_Code(Emp_Number) AS Post_Code
FROM dbo.Personnel_Detail;


---------------------------------------

SELECT * 
FROM INFORMATION_SCHEMA.TABLES
WHERE TABLE_NAME = 'Personnel_Detail';

SELECT DB_NAME() AS CurrentDatabase;

SELECT TABLE_SCHEMA, TABLE_NAME
FROM INFORMATION_SCHEMA.TABLES
WHERE TABLE_NAME = 'Personnel_Detail';