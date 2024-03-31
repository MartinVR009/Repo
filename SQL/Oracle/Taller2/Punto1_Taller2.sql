/*- Jleon.pokedex
- Jleon. pokemon_abilities
- Jleon. ABILITY_NAMES
- Jleon.languaje
- Jleon.pokedex_2*/

SELECT * 
FROM JLEON.pokedex;

SELECT * 
FROM JLEON.pokemon_abilities;

SELECT * 
FROM JLEON.ABILITY_NAMES;

SELECT * 
FROM JLEON.languaje;

SELECT * 
FROM JLEON.pokedex_2;

--Punto1
CREATE VIEW Punto1_Parte1 as(
SELECT pk.id_p, pk.identifier_p, an.ability_id, an.name_a
FROM JLEON.POKEMON_ABILITIES PA
INNER JOIN JLEON.ABILITY_NAMES AN
ON pa.ability_id = an.ability_id AND an.local_language_id = 9 
INNER JOIN JLEON.pokedex PK
ON pa.pokemon_id = pk.id_p
);
GRANT SELECT ON is354917.Punto1_Parte1 TO JLEON;

--Punto 2
CREATE VIEW Punto2_Parte1 as(
SELECT pk.id_p, pk.identifier_p
FROM JLEON.pokedex PK
LEFT JOIN JLEON.pokedex_2 PK2
ON pk.id_p = pk2.id
WHERE pk2.id IS NULL
);
GRANT SELECT ON is354917.Punto2_Parte1 TO JLEON;

--Punto3

CREATE VIEW Punto3_Parte1 as(
SELECT pk2.id, pk2.name, an.ability_id, an.name_a, pk2.generation
FROM JLEON.POKEMON_ABILITIES PA
INNER JOIN JLEON.ABILITY_NAMES AN
ON pa.ability_id = an.ability_id AND an.local_language_id = 1 
INNER JOIN JLEON.pokedex_2 PK2
ON pa.pokemon_id = pk2.id AND pk2.generation = 1
order by pk2.id
);

GRANT SELECT ON is354917.Punto3_Parte1 TO JLEON;

--Punto4

CREATE VIEW Punto4_Parte1 as(
SELECT count(PK2.id) as "TOTAL_TEMPORADA"
FROM JLEON.pokedex_2 PK2
GROUP BY PK2.generation
);

GRANT SELECT ON is354917.Punto4_Parte1 TO JLEON;


--Punto5

CREATE VIEW Punto5_Parte1 as(
SELECT PK2.type_1 as "Tipo", PK2.generation as "Temporada", COUNT(PK2.id) as "Total"
FROM JLEON.pokedex_2 PK2
GROUP BY PK2.type_1, PK2.generation
HAVING COUNT(PK2.id) > 10
order by PK2.generation
);
GRANT SELECT ON is354917.Punto5_Parte1 TO JLEON;




