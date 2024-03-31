//a. 
db.totalDocuments.aggregate([
	{
		$lookup: {
			from: “ratings”,
			localField: “movieId”,
			foreignField: “movieId”,
			as: “totalRatingMovies”,
		},
	},
	{
		$unwind: “$totalRatingMovies”,
	},
	{
		$lookup: {
			from: “películas”,
			localField: “movieId”,
			foreignField: “movieId”,
			as: “totalMovies”
		},
	},
	{
		$unwind: “$totalMovies”,
	},
	{
		$lookup: {
			from: “usuarios”,
			localField: “userId”,
			foreignField: “userId”,
			as: “totalUsuarios”,
		},
	},
	{
		$unwind: “$totalUsuarios”
	},
	{
		$project: {
			movieId: 0,
			userId: 0,
			totalRatingMovies: {
				$size: “$totalRatingMovies”
			},
			totalMovies: {
				$size: “totalMovies”,
			},
			totalUsuarios: {
				$size: “totalUsuarios”,
			},
		},
	},
])
//b. 
db.ratings.aggregate([
    {
        $match: {rating: { $ne: null }}
    },
    {
        $lookup: {from: "peliculas", localField: "movieId", foreignField: "movieId",                	             as: "nombre”}
    },
    {
        $unwind: "$nombre"
    },
    {
        $lookup: {from: "usuarios", localField: "userId", foreignField: "userId", 
            as: "nombre" }
    },
    {
        $unwind: "$nombre"
    },
    {
        $project: {rating: rating, "peliculas.nameMovie": nombrePelicula,
        "usuario.nombre": nombreUsuario}
    }
])
//c. 
db.peliculas.aggregate([
	{
		$lookup: {
			from: “ratings”,
			localField: “movieId”,
			foreignField: “movieId”,
			as: “calificaciones
		}
	},
	{
		$unwind: “$calificaciones”
	},
	{
		$group: {
			movieId: “$rating”,
			promedio: { $avg: “$calificaciones.rating” }
		}
		}
])

//d.
db.peliculas.aggregate([
	{
		$lookup: {
			from: “ratings”,
			localField: “movieId”,
			foreignField: “movieId”,
			as: “calificaciones”
		}
	},
	{
		$unwind: “$calificaciones”
	},
	{	
		$group: {
			movieId: “$titulo”,
			totalCalificaciones: { $sum: 1}
		}
	},
	{
		$sort: {
			totalCalificaciones: -1
		}
	},
	{
		$limit: 10
	}
])

//e. 
db.peliculas.aggregate ([
	{
		$lookup: {
			from: “ratings”,
			localField: “movieId”,
			foreignField: “movieId”,
			as: “calificaciones”
		}
	},
	{
		$unwind: “$calificaciones”
	},
	{
		$group: {
		movieId: “$titulo”,
		promedio: { $avg: “$calificaciones.rating” }
		}
	},
	{
		$sort: {
			promedio: 1
		}
	},
	{
		$limit: 10
	}
])

//f. 
db.peliculas.find ([
	{
		$lookup: {
			from: “ratings”,
			localField: “movieId”,
			foreignField: “movieId”,
			as: “calificaciones”
		}
	},
	{
		$unwind: “$calificaciones”
	},
	{
		$group: {
			movieId: “$movieId”,
			titulo: {$first: “$titulo”},
			promedio: {$avg: “$calificaciones.rating”}
		}
	},
	{
		$sort: {promedio: -1}
	},
	{
		$limit: 1
	},
	{
		$project: {
			movieId: 0,
			tipo: “Mejor película”,
			titulo: 1,
			promedio: 1
		}
	},
	{
		$sort: {promedio: 1}
	},
	{
		limit: 1
	},
	{
		$project: {
			movieId: 0,
			tipo: “Peor película”,
			titulo: 1,
			promedio: 1
		}
	}
})


//g. 
db.peliculas.find({
	$and: [
		{genre: “Acción” },
		{genre: “Ciencia ficcion”}
	]
})

//h. 
db.peliculas.find({
	$or: [
		{genre: “Comedia”},
		{genre: “Fantasia”}
	]
})

//i.
Para hacer uso o más bien simular la función map reduce en Mongo, se tendría que hacer uso de las funciones incluidas en aggregation pipeline para obtener un resultado alternativo al del map reduce. Para esto se haría uso de funciones como match, sort , limit,Project unwind, group, merge y finalize para así generar un código que nos muestre resultados como los que nos mostraría un map reduce  


//j. 
db.peliculas.find({
	“nombre”: { $regex: /police/i}
})

//k. 
db.ratings.aggregate([

{
	$group: { _id:userId, rating:{$sum:1}}
},

	{
$lookup: {from: "usuarios", localField: "userId", foreignField: "userId", as: "nombre"}
     },

    {
        $unwind: "$nombre"
	},

{
$project: {nombre: “$nombreUsuario”}
},

{
	$sort: {rating:-1}
},

{
	$limit:10
}
])

