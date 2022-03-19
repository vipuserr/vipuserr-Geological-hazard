#pragma once

#ifndef LIBS3DMGRPC_API
	#pragma comment(lib, "libS3DMApiGRPC.lib")
	#define LIBS3DMGRPC_API __declspec(dllimport)
#endif

#include <grpcpp/channel.h>
#include <common/pagination.pb.h>
#include <data_engine/data_engine.grpc.pb.h>
#include <sessions/sessions.grpc.pb.h>
#include <user_manager/user_manager.grpc.pb.h>
#include <map_service/map_service.grpc.pb.h>
#include <model_exporter/model_exporter.grpc.pb.h>

namespace smart3dmap {

	class LIBS3DMGRPC_API RequestContext {
	public:
		RequestContext();
		virtual ~RequestContext();

		/// @brief ȡ������ grpc::Context ����
		grpc::ClientContext* GetPtr() const;

	private:
		grpc::ClientContext* ctxClient_;
	};

    class LIBS3DMGRPC_API Client {
    public:
        /// @brief ��ʼ���ͻ��ˡ�
        /// @param serverURL ��������ַ����ʽΪ��"grpc://192.168.1.123:3000"��"grpcs://192.168.1.123:3000"��
        /// @param accessKey ���ڱ�ʶ��������ݵ�Access Key��û�з���ʱ��Ϊ�ա�
        /// @param secretKey ���ڱ�ʶ��������ݵ�Secret Key��û�з���ʱ��Ϊ�ա�
        static void Init(const char* serverURL, const char* accessKey = nullptr, const char* secretKey = nullptr);

        /// @brief ����֧�ֿͻ��˷�����ͨ�ŵ�grpc::Channel����
        /// @return ��Ӧ��grpc::Channel���󡣸÷��صĶ���ɱ�����ʹ�á�
        static std::shared_ptr<grpc::ChannelInterface> CreateChannel();

        /// @brief ���õ�ǰ��¼�û��ĻỰ��ʶ�����÷������̰߳�ȫ�ġ�
        /// @param token �Ự�ı�ʶ����Ϊ���ַ������ʶ��������õ�ֵ��
        static void SetUserSessionToken(const char* token);

		/// @brief �����ͻ��� grpc::ClientContext��
		static std::unique_ptr<RequestContext> NewContext();

		static std::unique_ptr<v1::DataEngine::StubInterface> NewDataEngineStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
		static std::unique_ptr<v1::SessionsManager::StubInterface> NewSessionsManagerStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
		static std::unique_ptr<v1::UserManager::StubInterface> NewUserManagerStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
		static std::unique_ptr<v1::MapService::StubInterface> NewMapServiceStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
		static std::unique_ptr<v1::ModelExport::StubInterface> NewModelExporterStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    };
}
