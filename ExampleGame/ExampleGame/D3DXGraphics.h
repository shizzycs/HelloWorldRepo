#ifndef D3DXGRAPHICS_H_DEFINED
#define D3DXGRAPHICS_H_DEFINED

#include "IGraphics.h"
#include <DirectXMath.h>
#include <d3d11.h>
#include <vector>

using namespace DirectX;

class D3DXGraphics : public IGraphics {
	struct VS_CONSTANT_BUFFER
	{
		XMFLOAT4X4 worldViewProj;
	};

	MESH_DATA *mBufferData;

	HWND hWnd;
	ID3D11Device *mDev;
	ID3D11DeviceContext *mDevCon;
	IDXGISwapChain *mSwapChain;
	ID3D11RenderTargetView *mBackBuffer;
	ID3D11InputLayout *mLayout;
	ID3D11VertexShader *mVShader;
	ID3D11PixelShader *mPShader;
	ID3D11Buffer *mVBuffer;
	ID3D11Buffer *mIBuffer;
	ID3D11Buffer *mCBuffer;

	int mICount;

	bool initD3D(HWND hWnd);
	bool initDeviceAndSwapChain(int width, int height);
	bool initRenderTarget();
	void createInputLayout(unsigned char *vShader, int vShaderSize);
	void updateBuffers(MESH_DATA *bufferData);
	bool initShaders();
	void initConstantBuffer();
	void updateConstantBuffer(VS_CONSTANT_BUFFER vsConstData);
	D3D11_VIEWPORT getViewport(int width, int height);

	public:
		D3DXGraphics();

		void updateScene(MESH_DATA *bufferData, float angle);
		void render();
		void setHWnd(HWND hWnd);

		~D3DXGraphics();
};

#endif
