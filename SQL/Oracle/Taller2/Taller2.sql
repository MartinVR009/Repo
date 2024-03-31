--Punto 12
CREATE VIEW Query1_Punto2 as(
SELECT constraint_name, constraint_type, search_condition FROM ALL_CONSTRAINTS
WHERE owner = 'JLEON'
AND TABLE_NAME = 'POKEDEX_2'
);
GRANT
    SELECT 
    ON
    is354917.Query1_Punto2
    TO
    jleon;

SELECT * 
FROM JLEON.POKEDEX_2;
--Punto12
CREATE VIEW Query2_Punto2 as(
SELECT column_name, data_type FROM ALL_TAB_COLUMNS
WHERE owner = 'JLEON'
AND TABLE_NAME = 'POKEDEX_2'
    );
    GRANT
    SELECT 
    ON
    is354917.Query2_Punto2
    TO
    jleon;
    
--Punto 12
DESC JLEON.POKEDEX_2;

--Punto1 12
CREATE VIEW Query4_Punto2 as(
SELECT *
FROM ALL_TAB_COLUMNS
WHERE OWNER = 'JLEON'
AND TABLE_NAME = 'POKEDEX_2'
);
GRANT
    SELECT 
    ON
    is354917.Query4_Punto2
    TO
    jleon;

--Punto 13
CREATE VIEW Query13_Punto2 as(
SELECT COUNT(*) "Total Registros"
FROM JLEON.POKEDEX_2 
);
GRANT
    SELECT 
    ON
    is354917.Query13_Punto2
    TO
    jleon;

--Punto 14
CREATE VIEW Query14_Punto2 as(
SELECT PK.ID, PK.NAME,PK.TYPE_1
FROM JLEON.POKEDEX_2 PK
WHERE PK.TYPE_1 = 'Water' OR PK.TYPE_1 = 'Ice'
);
GRANT
    SELECT 
    ON
    is354917.Query14_Punto2
    TO
    jleon;

--Punto 15
CREATE VIEW Query15_Punto2 as(
SELECT * 
FROM (
    SELECT PK.ID, PK.NAME, PK.speed
    FROM JLEON.POKEDEX_2 PK
    WHERE PK.GENERATION = '1'
    order by PK.SPEED desc
    )
WHERE ROWNUM <= 10
);

GRANT
    SELECT 
    ON
    is354917.Query15_Punto2
    TO
    jleon;

--Punto 16
CREATE VIEW Query16_Punto2 as(
SELECT PK.ID, PK.NAME, PK.ATTACK
FROM JLEON.POKEDEX_2 PK
WHERE PK.ATTACK BETWEEN 90 AND 150
order by 3 desc
);
GRANT
    SELECT 
    ON
    is354917.Query16_Punto2
    TO
    jleon;

--Punto 17
CREATE VIEW Query17_Punto2 as(
SELECT PK.GENERATION,
    COUNT(*) "Total Registros"
FROM JLEON.POKEDEX_2 PK
GROUP BY PK.GENERATION
);
GRANT
    SELECT 
    ON
    is354917.Query17_Punto2
    TO
    jleon;


--Punto 18
CREATE VIEW Query18_Punto2 as(
SELECT PK.NAME, PK.ID, PK.SPECIES
FROM JLEON.POKEDEX_2 PK
WHERE PK.SPECIES LIKE 'Bird%'
);
GRANT
    SELECT 
    ON
    is354917.Query18_Punto2
    TO
    jleon;

--hp, attack, defense,sp_attack, sp_defense, speed
--Punto 19
CREATE VIEW Query19_Punto2 as(
SELECT NAME,TOTAL_POINTS TP, (hp+ attack+ defense+sp_attack+ sp_defense+speed) "Total Puntos"
FROM JLEON.POKEDEX_2
);
GRANT
    SELECT 
    ON
    is354917.Query19_Punto2
    TO
    jleon;

--Punto 20
CREATE VIEW Query20_Punto2 as(
SELECT DISTINCT TYPE_1
FROM JLEON.POKEDEX_2
order by 1
);

/*
PK.TYPE_1 IN('Water','Ice','Dark')
*/




