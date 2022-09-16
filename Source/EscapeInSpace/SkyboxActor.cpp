// copyright anssi.grohn@karelia.fi 2019


#include "SkyboxActor.h"

// Sets default values
ASkyboxActor::ASkyboxActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>("Procedural Mesh");
	RootComponent = mesh;
}

// Called when the game starts or when spawned
void ASkyboxActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASkyboxActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASkyboxActor::GenerateSphere(int verticalSlices, int horizontalSlices)
{
	float R = 20.0f;
	float angle = 0.0;
	float sinAngle;
	float cosAngle;

	FMath::SinCos(&sinAngle, &cosAngle, angle);

	Vertices.Add(FVector(0, 0, R)); //0

	Vertices.Add(FVector(R, 0, 0));
	Vertices.Add(FVector(0, R, 0));
	Vertices.Add(FVector(-R, 0, 0));
	Vertices.Add(FVector(0, -R, 0));

	Vertices.Add(FVector(0, 0, -R)); // 5

	TexCoords.Add(FVector2D(0.5,1));

	TexCoords.Add(FVector2D( 0.0, 0.5));
	TexCoords.Add(FVector2D( 0.25, 0.5));
	TexCoords.Add(FVector2D( 0.5, 0.5));
	TexCoords.Add(FVector2D( 0.75, 0.5));

	TexCoords.Add(FVector2D(0.5,0.0));

	//ylapyramidi
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);
	
	Triangles.Add(0);
	Triangles.Add(2);
	Triangles.Add(3);

	Triangles.Add(0);
	Triangles.Add(3);
	Triangles.Add(4);

	Triangles.Add(0);
	Triangles.Add(4);
	Triangles.Add(1);

	//alapyramidi
	Triangles.Add(5);
	Triangles.Add(2);
	Triangles.Add(1);

	Triangles.Add(5);
	Triangles.Add(3);
	Triangles.Add(2);

	Triangles.Add(5);
	Triangles.Add(4);
	Triangles.Add(3);

	Triangles.Add(5);
	Triangles.Add(1);
	Triangles.Add(4);

	
	// luodaan varsinainen mesh
	mesh -> CreateMeshSection_LinearColor(0, Vertices, Triangles, TArray<FVector>(), TexCoords, TArray<FLinearColor>(), TArray<FProcMeshTangent>(), true);
}

void ASkyboxActor::PostActorCreated()
{
	GenerateSphere(0, 0);
}