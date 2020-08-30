#pragma once
#include <Tera/Core.h>

class TextureProcessor {
public:
  enum class TCFormat {
    None = 0,
    DXT1,
    DXT3,
    DXT5,
    RGBA8,
    PNG,
    TGA
  };

  TextureProcessor(TCFormat from, TCFormat to)
    : InputFormat(from)
    , OutputFormat(to)
  {}

  ~TextureProcessor()
  {
    free(InputData);
    free(OutputData);
  }

  inline void SetInputData(void* data, int32 size)
  {
    if (!data || size <= 0)
    {
      InputData = nullptr;
      InputDataSize = 0;
    }
    else
    {
      InputData = malloc(size);
      InputDataSize = size;
      memcpy(InputData, data, size);
    }
  }

  inline void SetInputDataDimensions(int32 sizeX, int32 sizeY)
  {
    InputDataSizeX = sizeX;
    InputDataSizeY = sizeY;
  }

  inline void SetInputPath(const std::string& inputPath)
  {
    InputPath = inputPath;
  }

  inline void SetOutputPath(const std::string& outputPath)
  {
    OutputPath = outputPath;
  }

  inline std::string GetError() const
  {
    return Error;
  }

  inline void SetSrgb(bool srgb)
  {
    SRGB = srgb;
  }

  inline void SetNormal(bool normal)
  {
    Normal = normal;
  }

  inline void SetAddressX(TextureAddress x)
  {
    AddressX = x;
  }

  inline void SetAddressY(TextureAddress y)
  {
    AddressY = y;
  }

  inline void SetGenerateMips(bool generate)
  {
    GenerateMips = generate;
  }

  inline void SetMipFilter(MipFilterType filter)
  {
    MipFilter = filter;
  }

  inline bool GetAlpha() const
  {
    return Alpha;
  }

  bool Process();

  struct OutputMip {
    int32 SizeX = 0;
    int32 SizeY = 0;
    int32 Size = 0;
    void* Data = nullptr;
  };

  inline const std::vector<OutputMip>& GetOutputMips() const
  {
    return OutputMips;
  }

private:
  bool BytesToFile();
  bool BytesToBytes();
  bool FileToBytes();

private:
  TCFormat InputFormat = TCFormat::None;
  TCFormat OutputFormat = TCFormat::None;

  void* InputData = nullptr;
  int32 InputDataSize = 0;
  int32 InputDataSizeX = 0;
  int32 InputDataSizeY = 0;
  std::string InputPath;

  void* OutputData = nullptr;
  int32 OutputDataSize = 0;
  int32 OutputMipCount = 0;

  std::vector<OutputMip> OutputMips;

  std::string OutputPath;
  
  bool SRGB = false;
  bool Alpha = false;
  bool Normal = false;
  bool GenerateMips = false;

  MipFilterType MipFilter = MipFilterType::Mitchell;

  TextureAddress AddressX = TA_Wrap;
  TextureAddress AddressY = TA_Wrap;

  std::string Error;
};