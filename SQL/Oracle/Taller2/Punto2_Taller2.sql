/*
- MOV_ROLES
- MOV_MOVIES
- MOV_ACTORS
- MOV_MOVIES_GENRERS
- MOV_MOVIES_DIRECTORS
- MOV_DIRECTORS
- MOV_DIRECTORS_GENRERS
*/


desc JLEON.MOV_ROLES;

SELECT *
FROM JLEON.MOV_ROLES;

SELECT * 
FROM JLEON.MOV_MOVIES;

SELECT *
FROM JLEON.MOV_ACTORS;

SELECT *
FROM JLEON.MOV_MOVIES_GENRERS;

SELECT *
FROM JLEON.MOV_MOVIES_DIRECTORS;

SELECT *
FROM JLEON.MOV_DIRECTORS;

SELECT *
FROM JLEON.MOV_DIRECTORS_GENRERS;

--Punto6
CREATE VIEW Punto6_Parte2 as(
SELECT * FROM ALL_CONSTRAINTS
where owner ='JLEON' and table_name in (
    'MOV_ROLES',
    'MOV_MOVIES',
    'MOV_ACTORS', 
    'MOV_MOVIES_GENRERS', 
    'MOV_MOVIES_DIRECTORS', 
    'MOV_DIRECTORS', 
    'MOV_DIRECTORS_GENRERS'
)
and constraint_type in ('R','P')
order by table_name
);
GRANT SELECT ON is354917.Punto6_Parte2 TO JLEON;


select * from all_cons_columns
where constraint_name ='MOVIES_DIRECTORS_IBFK_2';

--Punto7
CREATE VIEW Punto7_Parte2 as (
SELECT TO_CHAR(AVG(MM.RANK), 'fm990.00') "Promedio", MM.YEAR
FROM JLEON.MOV_MOVIES MM
GROUP BY MM.YEAR
ORDER BY MM.YEAR
);

GRANT SELECT ON is354917.Punto7_Parte2 TO JLEON;
--Punto 8

CREATE VIEW Punto8_Parte2 as(
SELECT DISTINCT
     MDD.FIRST_NAME, MDD.LAST_NAME, COUNT(MR.ACTOR_ID)
FROM 
    --(select distinct ACTOR_ID, MOVIE_ID from JLEON.MOV_ROLES ) MR ,
    JLEON.MOV_ROLES MR, 
    JLEON.MOV_MOVIES_DIRECTORS MD, 
    JLEON.MOV_DIRECTORS MDD
WHERE 
    MR.MOVIE_ID = MD.MOVIE_ID
    AND MD.DIRECTOR_ID=MDD.ID    
GROUP BY 
    MDD.FIRST_NAME, MDD.LAST_NAME
order by 1,2
);
GRANT SELECT ON is354917.Punto8_Parte2 TO JLEON;

--Punto 9

GRANT SELECT ON is354917.Punto9_Parte2 TO JLEON;
CREATE VIEW Punto9_Parte2 as(
SELECT M.GENRE , TO_CHAR(AVG(MM.RANK),'fm990.00') as "Promedio Genero"
FROM 
    JLEON.MOV_MOVIES_GENRERS M, 
    JLEON.MOV_MOVIES MM
WHERE 
    M.MOVIE_ID = MM.ID
GROUP BY 
    M.GENRE
    );
    

--Punto 10

CREATE VIEW Punto10_Parte2 as(
SELECT distinct MDG.GENRE
FROM 
    JLEON.MOV_DIRECTORS_GENRERS MDG      
    LEFT JOIN     
    JLEON.MOV_MOVIES_GENRERS M
    ON 
         MDG.genre=m.genre
WHERE M.GENRE IS NULL
);
GRANT SELECT ON is354917.Punto10_Parte2 TO JLEON;

--Punto 11
/*
No por que de todas formas los Joins 
solo mostrarian tomarian valores conjuntos 
de cada una de las tablas mas un Select especifico 
en las constraints y sus tipos ademas del nombre
de donde salen es mas acertado a saber como
se relacionan entre si
*/


