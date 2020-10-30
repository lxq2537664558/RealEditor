#include "UObject.h"
#include "FObjectResource.h"
#include "FName.h"

#include "UClass.h"
#include "UProperty.h"
#include "UMetaData.h"

// Components
#include "UComponent.h"

// Objects
#include "UObjectRedirector.h"
#include "UMaterial.h"
#include "UPersistentCookerData.h"
#include "UTexture.h"
#include "USkeletalMesh.h"
#include "UStaticMesh.h"
#include "USoundNode.h"
#include "UAnimSequence.h"
#include "UPhysAsset.h"

#include "UActor.h"
#include "ULevel.h"

UObject* UObject::Object(FObjectExport* exp)
{
  UObject* result = nullptr;
  const FString c = exp->GetClassName();
  if (c == UClass::StaticClassName())
  {
    result = new UClass(exp, false);
  }
  else if (c == UTexture2D::StaticClassName())
  {
    result = new UTexture2D(exp);
  }
  else if (c == USkeletalMesh::StaticClassName())
  {
    result = new USkeletalMesh(exp);
  }
  else if (c == UMaterial::StaticClassName())
  {
    result = new UMaterial(exp);
  }
  else if (c == UMaterialInstance::StaticClassName())
  {
    result = new UMaterialInstance(exp);
  }
  else if (c == UMaterialInstanceConstant::StaticClassName())
  {
    result = new UMaterialInstanceConstant(exp);
  }
  else if (c == UStaticMesh::StaticClassName())
  {
    result = new UStaticMesh(exp);
  }
  else if (c == URB_BodySetup::StaticClassName())
  {
    result = new URB_BodySetup(exp);
  }
  else if (c == UPhysicsAssetInstance::StaticClassName())
  {
    result = new UPhysicsAssetInstance(exp);
  }
  else if (c == UActor::StaticClassName())
  {
    result = new UActor(exp);
  }
  else if (c == ULevel::StaticClassName())
  {
    result = new ULevel(exp);
  }
  else if (c == UStaticMeshActor::StaticClassName())
  {
    result = new UStaticMeshActor(exp);
  }
  else if (c == UAnimSequence::StaticClassName())
  {
    result = new UAnimSequence(exp);
  }
  else if (c == USoundNodeWave::StaticClassName())
  {
    result = new USoundNodeWave(exp);
  }
  else if (c == UField::StaticClassName())
  {
    result = new UField(exp);
  }
  else if (c == UStruct::StaticClassName())
  {
    result = new UStruct(exp);
  }
  else if (c == UScriptStruct::StaticClassName())
  {
    result = new UScriptStruct(exp);
  }
  else if (c == UState::StaticClassName())
  {
    result = new UState(exp);
  }
  else if (c == UEnum::StaticClassName())
  {
    result = new UEnum(exp);
  }
  else if (c == UConst::StaticClassName())
  {
    result = new UConst(exp);
  }
  else if (c == UFunction::StaticClassName())
  {
    result = new UFunction(exp);
  }
  else if (c == UTextBuffer::StaticClassName())
  {
    result = new UTextBuffer(exp);
  }
  else if (c == UIntProperty::StaticClassName())
  {
    result = new UIntProperty(exp);
  }
  else if (c == UBoolProperty::StaticClassName())
  {
    result = new UBoolProperty(exp);
  }
  else if (c == UByteProperty::StaticClassName())
  {
    result = new UByteProperty(exp);
  }
  else if (c == UFloatProperty::StaticClassName())
  {
    result = new UFloatProperty(exp);
  }
  else if (c == UObjectProperty::StaticClassName())
  {
    result = new UObjectProperty(exp);
  }
  else if (c == UClassProperty::StaticClassName())
  {
    result = new UClassProperty(exp);
  }
  else if (c == UComponentProperty::StaticClassName())
  {
    result = new UComponentProperty(exp);
  }
  else if (c == UNameProperty::StaticClassName())
  {
    result = new UNameProperty(exp);
  }
  else if (c == UStrProperty::StaticClassName())
  {
    result = new UStrProperty(exp);
  }
  else if (c == UStructProperty::StaticClassName())
  {
    result = new UStructProperty(exp);
  }
  else if (c == UArrayProperty::StaticClassName())
  {
    result = new UArrayProperty(exp);
  }
  else if (c == UMapProperty::StaticClassName())
  {
    result = new UMapProperty(exp);
  }
  else if (c == UInterfaceProperty::StaticClassName())
  {
    result = new UInterfaceProperty(exp);
  }
  else if (c == UDelegateProperty::StaticClassName())
  {
    result = new UDelegateProperty(exp);
  }
  else if (c == UMetaData::StaticClassName())
  {
    result = new UMetaData(exp);
  }
  else if (c == UObjectRedirector::StaticClassName())
  {
    result = new UObjectRedirector(exp);
  }
  else if (c == UPersistentCookerData::StaticClassName())
  {
    result = new UPersistentCookerData(exp);
  }
  else if (c == UMaterialExpressionComponentMask::StaticClassName())
  {
    result = new UMaterialExpressionComponentMask(exp);
  }
  else if (c == UComponent::StaticClassName())
  {
    result = new UComponent(exp);
  }
  else if (c == UStaticMeshComponent::StaticClassName())
  {
    result = new UStaticMeshComponent(exp);
  }
  else if (c == UDominantDirectionalLightComponent::StaticClassName())
  {
    result = new UDominantDirectionalLightComponent(exp);
  }
  else if (c == UDominantSpotLightComponent::StaticClassName())
  {
    result = new UDominantSpotLightComponent(exp);
  }
  else
  {
    // Fallback for unimplemented components. *Component => UComponent
    if ((c.Find(UComponent::StaticClassName()) != std::string::npos) ||
        (c.Find("Distribution") != std::string::npos))
    {
      result = new UComponent(exp);
    }
    // Fallback for all *Actor classes except components
    else if (c.Find(NAME_Actor) != std::string::npos && c != NAME_ActorFactory)
    {
      result = new UActor(exp);
    }
    else
    {
      result = new UObject(exp);
    }
  }
  return result;
}