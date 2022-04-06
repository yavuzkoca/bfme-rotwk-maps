 

				
 		; ------------------------ Wight Anims -------------------------
	          AnimationState							= FREEFALL 
			Animation							= FLYA
				AnimationName					= CUWight_FLYA
				AnimationMode					= LOOP
				AnimationBlendTime				= 5
			End
		End
		
		;//Normal Swipe Attack
		AnimationState        = FIRING_OR_PREATTACK_A 
			Animation           = ATKA
				AnimationName     = CUWight_ATKA
				AnimationMode     = ONCE
				UseWeaponTiming	  = Yes
			End
			StateName           = Attack
		End
		
		AnimationState        = MOVING 
			Animation           = RUNA
				AnimationName     = CUWight_RUNA
				AnimationMode     = LOOP
			End
			Flags               = RANDOMSTART
		End
		
		AnimationState							= SPLATTED
			Animation							= LNDA
				AnimationName					= CUWight_LNDA
				AnimationMode					= ONCE
			End
		End
		
		AnimationState = DYING
			Animation = DIEA
				AnimationName = CUWight_DIEA
			    AnimationMode = ONCE
				AnimationPriority = 1
			End
		End		
		
		AnimationState        = STUNNED_STANDING_UP 
			Animation           = GTPA
				AnimationName     = CUWight_GTPA
				AnimationMode     = ONCE
			End
		End

		AnimationState        = STUNNED 
			Animation           = LNDA
				AnimationName     = CUWight_LNDA
				AnimationMode     = ONCE
			End
		End
		
		; --------- Hit Reactions ------------
		AnimationState = HIT_REACTION HIT_LEVEL_1 
			Animation = Hit_Level_1_a
				AnimationName = CUWight_HITA
				AnimationMode = ONCE
			End
		End		
		
		;-emotions--
		
		AnimationState							= EMOTION_TAUNTING 
			Animation							= TNTA
				AnimationName					= CUWight_TNTA
				AnimationMode					= LOOP
			End
		End
	
		AnimationState							= EMOTION_CELEBRATING 
			Animation                           = CHRA
				AnimationName					= CUWight_CHRA
				AnimationMode					= ONCE
			End
		End

 		IdleAnimationState
			Animation = IDLA
				AnimationName		= CUWight_IDLA
				AnimationMode		= ONCE
				AnimationBlendTime	= 30
				AnimationPriority	= 1 ;2
			End
			Animation = IDLB
				AnimationName		= CUWight_IDLB
				AnimationMode		= ONCE
				AnimationBlendTime	= 30
				AnimationPriority	= 20
			End
		End		

	End
	
	; ---------------------------- End Wight Anims --------------------------------
	
