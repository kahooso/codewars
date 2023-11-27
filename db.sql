create table employee(
    id int primary key identity not null,
    first_name nvarchar(max),
    last_name nvarchar(max),
    date_of_birth date,
    country_of_birth nvarchar(max),
    phone nvarchar(max)
)