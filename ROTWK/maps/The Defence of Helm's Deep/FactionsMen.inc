;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;Editing Factions;;;;;;;;;;;;;;;;;;;;;;;;;;
PlayerTemplate FactionMen
Side						= Men
Evil	          = No
StartingUnit1 = NONE                      ;;;;;  So no starting builders
StartingUnit0 = NONE
StartingBuilding = NONE                   ;;;;;  No starting fortress. This will triger the instant defeat of the faction if you don't manualy plant another building for it on the map
BuildableHeroesMP			= CreateAHero
InitialUpgrades				= Upgrade_MenFaction
IntrinsicSciences			= SCIENCE_GOOD
	IntrinsicSciencesMP 		= SCIENCE_MEN
	SpellBook					= GoodSpellBook
	SpellBookMp					= MenSpellBook
	PurchaseScienceCommandSet	= GoodSpellStoreCommandSet
	PurchaseScienceCommandSetMP	= MenSpellStoreCommandSetNew
End

PlayerTemplate FactionElves
Side						= Men
Evil	          = No
StartingUnit1 = NONE
StartingUnit0 = NONE
StartingBuilding = NONE
BuildableHeroesMP			= CreateAHero
InitialUpgrades				= Upgrade_MenFaction
IntrinsicSciences			= SCIENCE_GOOD
	IntrinsicSciencesMP 		= SCIENCE_MEN
	SpellBook					= GoodSpellBook
	SpellBookMp					= MenSpellBook
	PurchaseScienceCommandSet	= GoodSpellStoreCommandSet
	PurchaseScienceCommandSetMP	= MenSpellStoreCommandSetNew
End

PlayerTemplate FactionDwarves
Side						= Men
Evil	          = No
StartingUnit1 = NONE
StartingUnit0 = NONE
StartingBuilding = NONE
BuildableHeroesMP			= CreateAHero
InitialUpgrades				= Upgrade_MenFaction
IntrinsicSciences			= SCIENCE_GOOD
	IntrinsicSciencesMP 		= SCIENCE_MEN
	SpellBook					= GoodSpellBook
	SpellBookMp					= MenSpellBook
	PurchaseScienceCommandSet	= GoodSpellStoreCommandSet
	PurchaseScienceCommandSetMP	= MenSpellStoreCommandSetNew
End

PlayerTemplate FactionIsengard
Side						= Men
Evil	          = No
StartingUnit1 = NONE
StartingUnit0 = NONE
StartingBuilding = NONE
BuildableHeroesMP			= CreateAHero
InitialUpgrades				= Upgrade_MenFaction
IntrinsicSciences			= SCIENCE_GOOD
	IntrinsicSciencesMP 		= SCIENCE_MEN
	SpellBook					= GoodSpellBook
	SpellBookMp					= MenSpellBook
	PurchaseScienceCommandSet	= GoodSpellStoreCommandSet
	PurchaseScienceCommandSetMP	= MenSpellStoreCommandSetNew
End

PlayerTemplate FactionMordor
Side						= Men
Evil	          = No
StartingUnit1 = NONE
StartingUnit0 = NONE
StartingBuilding = NONE
BuildableHeroesMP			= CreateAHero
InitialUpgrades				= Upgrade_MenFaction
IntrinsicSciences			= SCIENCE_GOOD
	IntrinsicSciencesMP 		= SCIENCE_MEN
	SpellBook					= GoodSpellBook
	SpellBookMp					= MenSpellBook
	PurchaseScienceCommandSet	= GoodSpellStoreCommandSet
	PurchaseScienceCommandSetMP	= MenSpellStoreCommandSetNew
End

PlayerTemplate FactionWild
Side						= Men
Evil	          = No
StartingUnit1 = NONE
StartingUnit0 = NONE
StartingBuilding = NONE
BuildableHeroesMP			= CreateAHero
InitialUpgrades				= Upgrade_MenFaction
IntrinsicSciences			= SCIENCE_GOOD
	IntrinsicSciencesMP 		= SCIENCE_MEN
	SpellBook					= GoodSpellBook
	SpellBookMp					= MenSpellBook
	PurchaseScienceCommandSet	= GoodSpellStoreCommandSet
	PurchaseScienceCommandSetMP	= MenSpellStoreCommandSetNew
End

PlayerTemplate FactionAngmar
Side						= Men
Evil	          = No
StartingUnit1 = NONE
StartingUnit0 = NONE
StartingBuilding = NONE
BuildableHeroesMP			= CreateAHero
Evil	          = No
InitialUpgrades				= Upgrade_MenFaction
IntrinsicSciences			= SCIENCE_GOOD
	IntrinsicSciencesMP 		= SCIENCE_MEN
	SpellBook					= GoodSpellBook
	SpellBookMp					= MenSpellBook
	PurchaseScienceCommandSet	= GoodSpellStoreCommandSet
	PurchaseScienceCommandSetMP	= MenSpellStoreCommandSetNew
End

PlayerTemplate FactionCivilian            
	InitialUpgrades				= Upgrade_WildFaction Upgrade_GoblinDualEconomyChoice Upgrade_EvilDualEconomyChoice
	IntrinsicSciences			= SCIENCE_EVIL
	IntrinsicSciencesMP			= SCIENCE_EVIL
	SpellBook				= EvilSpellBook
	SpellBookMp				= EvilSpellBook
        PurchaseScienceCommandSetMP = EvilSpellStoreCommandSet                            
End
