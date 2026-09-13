-- 1. Tạo 6 Login và User tương ứng từ u1 đến u6
CREATE LOGIN u1 WITH PASSWORD = 'Password123!';
CREATE USER u1 FOR LOGIN u1;

CREATE LOGIN u2 WITH PASSWORD = 'Password123!';
CREATE USER u2 FOR LOGIN u2;

CREATE LOGIN u3 WITH PASSWORD = 'Password123!';
CREATE USER u3 FOR LOGIN u3;

CREATE LOGIN u4 WITH PASSWORD = 'Password123!';
CREATE USER u4 FOR LOGIN u4;

CREATE LOGIN u5 WITH PASSWORD = 'Password123!';
CREATE USER u5 FOR LOGIN u5;

CREATE LOGIN u6 WITH PASSWORD = 'Password123!';
CREATE USER u6 FOR LOGIN u6;

-- 2. Tạo 3 Database Role từ r1 đến r3
CREATE ROLE r1;
CREATE ROLE r2;
CREATE ROLE r3;

 -- 3. Gán User vào các Role tương ứng
ALTER ROLE r1 ADD MEMBER u1;

ALTER ROLE r2 ADD MEMBER u2;
ALTER ROLE r2 ADD MEMBER u3;

ALTER ROLE r3 ADD MEMBER u4;
ALTER ROLE r3 ADD MEMBER u5;
ALTER ROLE r3 ADD MEMBER u6;

-- 4.1. Thực hiện cho r2 và r3 đối với các Database Role (db_owner, db_accessadmin)
ALTER ROLE db_owner ADD MEMBER r2;
ALTER ROLE db_accessadmin ADD MEMBER r2;

ALTER ROLE db_owner ADD MEMBER r3;
ALTER ROLE db_accessadmin ADD MEMBER r3;

-- 4.2. Đối với SysAdmin (Server Role):
-- Do sysadmin không thể thêm Database Role (r1, r3) làm thành viên, 
-- ta cần gán trực tiếp các Login thuộc r1 (u1) và r3 (u4, u5, u6) vào sysadmin:
ALTER SERVER ROLE sysadmin ADD MEMBER u1; -- Thuộc r1
ALTER SERVER ROLE sysadmin ADD MEMBER u4; -- Thuộc r3
ALTER SERVER ROLE sysadmin ADD MEMBER u5; -- Thuộc r3
ALTER SERVER ROLE sysadmin ADD MEMBER u6; -- Thuộc r3

-- 1. Kiểm tra thành viên của các Database Role (r1, r2, r3 và db_owner, db_accessadmin)
SELECT 
    r.name AS [Database_Role],
    m.name AS [Member_Name],
    m.type_desc AS [Member_Type]
FROM sys.database_role_members rm
JOIN sys.database_principals r ON rm.role_principal_id = r.principal_id
JOIN sys.database_principals m ON rm.member_principal_id = m.principal_id
WHERE r.name IN ('r1', 'r2', 'r3', 'db_owner', 'db_accessadmin')
ORDER BY r.name, m.name;

-- 2. Kiểm tra các Login có quyền sysadmin (Server Role)
SELECT 
    p.name AS [Server_Role],
    m.name AS [Login_Name]
FROM sys.server_role_members rm
JOIN sys.server_principals p ON rm.role_principal_id = p.principal_id
JOIN sys.server_principals m ON rm.member_principal_id = m.principal_id
WHERE p.name = 'sysadmin' AND m.name IN ('u1', 'u2', 'u3', 'u4', 'u5', 'u6')
ORDER BY m.name;
