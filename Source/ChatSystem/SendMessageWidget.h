// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SendMessageWidget.generated.h"

/**
 * 
 */
UCLASS()
class CHATSYSTEM_API USendMessageWidget : public UUserWidget
{
	GENERATED_BODY()


protected:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UEditableTextBox> MessageBox;

public:
	UFUNCTION()
	void CommitedMessageBox(const FText& Text, ETextCommit::Type CommitType);
	
};
