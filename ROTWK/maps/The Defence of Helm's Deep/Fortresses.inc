
;;;;;;;;;;;;;;;;;;;;;;;;Modding fortresses so they display even if they belong to PlyrCivilian
Object MenFortress
ReplaceModule ModuleTag_castle
Behavior = CastleBehavior ModuleTag_castleNew
		CastleToUnpackForFaction	= Men Fortress_Men
		CastleToUnpackForFaction	= Elves Fortress_Men
		CastleToUnpackForFaction	= Dwarves Fortress_Men		
		CastleToUnpackForFaction	= Wild Fortress_Men
		CastleToUnpackForFaction	= Isengard Fortress_Men
		CastleToUnpackForFaction	= Mordor Fortress_Men
		CastleToUnpackForFaction	= Angmar Fortress_Men
		CastleToUnpackForFaction	= Civilian Fortress_Men

		FilterValidOwnedEntries = ANY +STRUCTURE +WALK_ON_TOP_OF_WALL +BASE_FOUNDATION +TACTICAL_MARKER		;Anything that does not fit this filter will be given to the neutral player, so the template can have rocks and props.

		MaxCastleRadius				= 130.0
		InstantUnpack				= Yes		
		KeepDeathKillsEverything	= Yes

		EvaEnemyCastleSightedEvent = EnemyFortressSighted
	End 
End
End

Object ElvenFortress
ReplaceModule ModuleTag_castle
Behavior = CastleBehavior ModuleTag_castleNew
		CastleToUnpackForFaction	= Men Fortress_Elves
		CastleToUnpackForFaction	= Elves Fortress_Elves
		CastleToUnpackForFaction	= Dwarves Fortress_Elves		
		CastleToUnpackForFaction	= Wild Fortress_Elves
		CastleToUnpackForFaction	= Isengard Fortress_Elves
		CastleToUnpackForFaction	= Mordor Fortress_Elves
		CastleToUnpackForFaction	= Angmar Fortress_Elves
		CastleToUnpackForFaction	= Civilian Fortress_Elves

		FilterValidOwnedEntries = ANY +STRUCTURE +WALK_ON_TOP_OF_WALL +BASE_FOUNDATION +TACTICAL_MARKER		;Anything that does not fit this filter will be given to the neutral player, so the template can have rocks and props.

		MaxCastleRadius				= 130.0
		InstantUnpack				= Yes		
		KeepDeathKillsEverything	= Yes

		EvaEnemyCastleSightedEvent = EnemyFortressSighted
	End 
End
End

Object DwarvenFortress
ReplaceModule ModuleTag_castle
Behavior = CastleBehavior ModuleTag_castleNew
		CastleToUnpackForFaction	= Men Fortress_Dwarven
		CastleToUnpackForFaction	= Elves Fortress_Dwarven
		CastleToUnpackForFaction	= Dwarves Fortress_Dwarven		
		CastleToUnpackForFaction	= Wild Fortress_Dwarven
		CastleToUnpackForFaction	= Isengard Fortress_Dwarven
		CastleToUnpackForFaction	= Mordor Fortress_Dwarven
		CastleToUnpackForFaction	= Angmar Fortress_Dwarven
		CastleToUnpackForFaction	= Civilian Fortress_Dwarven

		FilterValidOwnedEntries = ANY +STRUCTURE +WALK_ON_TOP_OF_WALL +BASE_FOUNDATION +TACTICAL_MARKER		;Anything that does not fit this filter will be given to the neutral player, so the template can have rocks and props.

		MaxCastleRadius				= 130.0
		InstantUnpack				= Yes		
		KeepDeathKillsEverything	= Yes

		EvaEnemyCastleSightedEvent = EnemyFortressSighted
	End 
End
End

Object MordorFortress
ReplaceModule ModuleTag_castle
Behavior = CastleBehavior ModuleTag_castleNew
		CastleToUnpackForFaction	= Mordor Fortress_Mordor
		CastleToUnpackForFaction	= Isengard Fortress_Mordor
		CastleToUnpackForFaction	= Men Fortress_Mordor
		CastleToUnpackForFaction	= Elves Fortress_Mordor
		CastleToUnpackForFaction	= Dwarves Fortress_Mordor		
		CastleToUnpackForFaction	= Wild Fortress_Mordor	
		CastleToUnpackForFaction	= Civilian Fortress_Mordor			

		//Anything that does not fit this filter will be given to the neutral player, so the template can have rocks and props.
		FilterValidOwnedEntries = ANY +STRUCTURE +WALK_ON_TOP_OF_WALL +BASE_FOUNDATION +TACTICAL_MARKER		

		MaxCastleRadius 			= 130.0
		InstantUnpack				= Yes		
		KeepDeathKillsEverything	= Yes

		EvaEnemyCastleSightedEvent = EnemyFortressSighted
	End 
End
End

