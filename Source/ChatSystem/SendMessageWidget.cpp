// Fill out your copyright notice in the Description page of Project Settings.


#include "SendMessageWidget.h"
#include "GameFramework/PlayerController.h"
#include "ChatSystemCharacter.h"
#include "Components/EditableTextBox.h" 

void USendMessageWidget::NativeConstruct()
{
    Super::NativeConstruct();

    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
    if (PlayerController)
    {
        FInputModeUIOnly InputModeData;
      //  InputModeData.SetWidgetToFocus(GetCachedWidget());
        PlayerController->SetInputMode(InputModeData);
        PlayerController->SetShowMouseCursor(true);
    }

    if (MessageBox)
    {
        MessageBox->OnTextCommitted.AddDynamic(this, &USendMessageWidget::CommitedMessageBox);
    }
}

void USendMessageWidget::CommitedMessageBox(const FText& Text, ETextCommit::Type CommitType)
{
    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
    if (PlayerController)
    {
        ACharacter* PlayerCharacter = PlayerController->GetCharacter();

        if (AChatSystemCharacter* ChatCharacter = Cast<AChatSystemCharacter>(PlayerCharacter))
        {
            ChatCharacter->AttemptToSendChatMessage(Text.ToString());

            FInputModeGameOnly InputModeData2;
            PlayerController->SetInputMode(InputModeData2);
            PlayerController->SetShowMouseCursor(false);

            RemoveFromParent();
            ChatCharacter->SendMessageWidget = nullptr;
        }
    }
}
