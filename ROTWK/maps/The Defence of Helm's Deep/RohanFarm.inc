;----------------------------------------------
; Editing the Rohan Farm

;----------------------------------------------
;The object itself

Object RohanFarm
	CommandPointBonus	= GENERIC_ECONOMY_COMMAND_POINT_BONUS
	RemoveModule  AutoDepositModuleTag
	
	AddModule
		Behavior = TerrainResourceBehavior ModuleTag_NewMoney
			Radius = GONDOR_FARM_MONEY_RANGE		; How far we try to claim ground
			MaxIncome = GONDOR_FARM_MONEY_AMOUNT	; If we were to get all we wanted, how much we would earn.  Linear slope to 0 at 0% claim
			IncomeInterval = GONDOR_FARM_MONEY_TIME	; How often (in msec) we give that much money
			Upgrade					= Upgrade_MarketplaceUpgradeGrandHarvest  
			UpgradeBonusPercent		= GONDOR_GRANDHARVEST_PRODUCTION_INCREASE %
			UpgradeMustBePresent	= ANY +GondorMarketPlace
		End
	End
	
	CommandSet          = RohanFarmCommandSetNew
	
	
END

;------------------------------------------------
;CommandSet

CommandSet RohanFarmCommandSetNew
	1	= Command_ConstructRohanPeasantHorde
	2 	= Command_ConstructRohanSpearmenHorde
	6	= Command_Sell
End
