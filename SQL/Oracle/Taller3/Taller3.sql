/*
- Jleon.pokedex
- Jleon.pokemon_abilities
- Jleon. ABILITY_NAMES
- Jleon.languaje
*/

--Punto 21
desc Jleon.pokedex;
desc Jleon.pokemon_abilities;
desc Jleon.ABILITY_NAMES;
desc Jleon.languaje;

SELECT COUNT(*) 
FROM Jleon.pokedex;

SELECT COUNT(*) 
FROM Jleon.pokemon_abilities;

SELECT COUNT(*) 
FROM Jleon.ABILITY_NAMES;

SELECT COUNT(*) 
FROM Jleon.languaje;

--
CREATE VIEW Query21_Punto3 as(
SELECT TABLE_NAME, CONSTRAINT_NAME, CONSTRAINT_TYPE, SEARCH_CONDITION, R_CONSTRAINT_NAME
FROM ALL_CONSTRAINTS
WHERE OWNER = 'JLEON'
AND TABLE_NAME IN ('POKEDEX','POKEMON_ABILITIES','ABILITY_NAMES','LANGUAJE')
order by 1
);
GRANT
    SELECT 
    ON
    is354917.Query21_Punto3
    TO
    jleon;

SELECT * 
FROM Jleon.pokedex;

SELECT *
FROM Jleon.pokemon_abilities;

SELECT *
FROM Jleon.ABILITY_NAMES;

SELECT *
FROM Jleon.languaje;

--Punto 23
CREATE VIEW Query23_Punto3 as(
SELECT P.ID_P, P.IDENTIFIER_P, AN.NAME_A
FROM  
    Jleon.pokedex P,
    Jleon.pokemon_abilities PA,
    Jleon. ABILITY_NAMES AN,
    Jleon.languaje L
WHERE 
    P.ID_P = PA.POKEMON_ID and 
    PA.ABILITY_ID = AN.ABILITY_ID and
    AN.LOCAL_LANGUAGE_ID = L.ID AND 
    L.ID = 7
    );
GRANT
    SELECT 
    ON
    is354917.Query23_Punto3
    TO
    jleon;

--Punto 24
CREATE VIEW Query24_Punto3 as(
SELECT 
    P.IDENTIFIER_P
FROM 
    Jleon.pokedex P
WHERE 
    UPPER(P.IDENTIFIER_P) LIKE 'S%' OR 
    UPPER(P.IDENTIFIER_P) LIKE 'Z%'
    );
    GRANT
    SELECT 
    ON
    is354917.Query23_Punto3
    TO
    jleon;
    
--Punto25
    CREATE VIEW Query25_Punto3 as(
SELECT 
    ID, NAME
FROM 
    JLEON.POKEDEX_2
    UNION
SELECT 
    ID_P, IDENTIFIER_P
FROM 
    JLEON.POKEDEX
ORDER BY 1
    );
GRANT
    SELECT 
    ON
    is354917.Query25_Punto3
    TO
    jleon;

--Punto26
CREATE VIEW Query26_Punto3 as(
SELECT DISTINCT ID, NAME
FROM(
    SELECT 
        ID, NAME
    FROM 
        JLEON.POKEDEX_2
        UNION
    SELECT 
        ID_P, IDENTIFIER_P
    FROM 
        JLEON.POKEDEX
    ORDER BY 1
    )
);
GRANT
    SELECT 
    ON
    is354917.Query26_Punto3
    TO
    jleon;

    
    


