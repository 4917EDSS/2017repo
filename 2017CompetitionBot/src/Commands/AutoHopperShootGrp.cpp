#include <Commands/AutoHopperShootGrp.h>
#include "SilkyDriveCmd.h"
#include "ShootCmd.h"
#include "SpinUpCmd.h"
#include <vector>
#include "SetHopperOpenCmd.h"
#include "OpenGearFlapsCmd.h"
#include "HopperPulseCmd.h"
#include "RunPickupCmd.h"
#include "SetIntakeCmd.h"


AutoHopperShootGrp::AutoHopperShootGrp() {

	//Get alliance
	bool blueSide = frc::DriverStation::GetInstance().GetAlliance() == frc::DriverStation::Alliance::kBlue;

	//Open hopper and gear flaps
	AddParallel(new OpenGearFlapsCmd(false));
	AddParallel(new SetHopperOpenCmd(true));

	if(blueside){
		AddSequential(new SilkyDriveCmd({0, -850, -1600, -3350, -3450}, {0, -850, -1600, -2700, -2800}));
		//Close Hopper
		AddParallel(new SetHopperOpenCmd(false));
		AddParallel(new ShootCmd(-KEY_SHOT_SHOOTER_SPEED, HOPPER_RECEIVE_TIME));
		AddSequential(new WaitCommand(HOPPER_WAIT_TIME));
		AddParallel(new SpinUpCmd(AUTO_BOILER_SHOT_SHOOTER_SPEED));
		AddParallel(new SetIntakeCmd(true));
		AddParallel(new RunPickupCmd());
		AddSequential(new SilkyDriveCmd({0, 1010, 2080, 2680, 3160}, {0, 330, 605, 880, 1380}));
		AddParallel(new HopperPulseCmd(10.0));
		AddSequential(new ShootCmd(BOILER_SHOT_SHOOTER_SPEED));
	}else{

	}

}
