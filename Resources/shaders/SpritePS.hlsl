struct PixelShaderOutput
{
    float4 color : SV_TARGETO;
};

PixelShaderOutput main()
{
    PixelShaderOutput output;
    output.color = float4(1.0f,1.0f,1.0f,1.0f);
    return output;
}