#pragma once 
#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/XboxController.h>
class NewPickupSubsystem : public frc2::SubsystemBase{
    public:
        NewPickupSubsystem(frc::XboxController* controller);
        void setIntakeMotor(double axis);
        void autoOut(bool isArmOut);
    private:
    frc::XboxController* m_driverController;
         WPI_VictorSPX pickUpMotor;

         int isCubePickup;
       
     void Periodic() override;   
};