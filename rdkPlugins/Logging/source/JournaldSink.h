#pragma once

#include "ILoggingSink.h"

#define PTY_BUFFER_SIZE 4096

class JournaldSink : public ILoggingSink
{
public:
    JournaldSink(const std::string &containerId, std::shared_ptr<rt_dobby_schema> &containerConfig);

public:
    void DumpLog(const int bufferFd, const bool startNewLog) override;

    void SetLogOptions(const IDobbyRdkLoggingPlugin::LoggingOptions& options) override;

    void process(const std::shared_ptr<AICommon::IPollLoop> &pollLoop, uint32_t events) override;

private:
    int mJournaldSteamFd;
    const std::shared_ptr<rt_dobby_schema> mContainerConfig;
    const std::string mContainerId;
    IDobbyRdkLoggingPlugin::LoggingOptions mLoggingOptions;
};