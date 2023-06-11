#pragma once 
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <frc/XboxController.h>
class NewPickupSubsystem : public frc2::SubsystemBase{
    public:
        NewPickupSubsystem(frc::XboxController* controller);
        void setIntakeMotor(double axis);
    private:
    frc::XboxController* m_driverController;
        rev::CANSparkMax pickUpMotor;
       
     void Periodic() override;   
};