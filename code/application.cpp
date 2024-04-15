#include "application.h"
#include "imgui.h"
#include "AsianOption.h"
#include "CRRBinomialTree.h"
#include "LookBack.h"
#include "Simulator.h"
#include "VanillaOption.h"

 
namespace Myapp
{
    void newwindow1()
    {
        static bool checkact1 = false;
        static bool checkapt1 = false;
        static bool checkect1 = false;
        static bool checkept1 = false;
        static bool checklcm1 = false;
        static bool checklpm1 = false;
        static bool checkvcm1 = false;
        static bool checkvpm1 = false;
        static bool checkacm1 = false;
        static bool checkapm1 = false;
        ImGui::Begin("new window");// Create a window called "Hello, world!" and append into it.
        ImGui::Text("We have two different methods, CRR binomial tree and Monte-Carlo Simutaions");
        ImGui::Text("All tree methods are vanilla options");
        ImGui::Text("All  Monte-Carlo methods are European options");
        ImGui::Text("option types:");
        ImGui::Text("");
        ImGui::Checkbox("American call option tree", &checkact1);
        ImGui::Checkbox("American put option tree", &checkapt1);
        ImGui::Checkbox("European call option tree", &checkect1);
        ImGui::Checkbox("European put option tree", &checkept1);

        ImGui::Checkbox("lookback call option M-C", &checklcm1);
        ImGui::Checkbox("lookback put option M-C", &checklpm1);

        ImGui::Checkbox("vanilla call option M-C", &checkvcm1);
        ImGui::Checkbox("vanilla put option M-C", &checkvpm1);

        ImGui::Checkbox("Asian call option M-C", &checkacm1);
        ImGui::Checkbox("Asian put option M-C", &checkapm1);

        ImGui::Separator();
        ImGui::Text("You can change parameters by clicking or typing ");
        ImGui::Text("parameter input:");
        ImGui::Text("");
        static float s10 = 0.0f;
        ImGui::InputFloat("Stock price", &s10, 0.001f, 1.0f, "%.5f");
        static float k10 = 0.0f;
        ImGui::InputFloat("Strike price", &k10, 0.001f, 1.0f, "%.5f");
        static float r10 = 0.0f;
        ImGui::InputFloat("risk-free-rate", &r10, 0.001f, 1.0f, "%.5f");
        static float q10 = 0.0f;
        ImGui::InputFloat("dividend", &q10, 0.001f, 1.0f, "%.5f");
        static float T10 = 0.0f;
        ImGui::InputFloat("Time to maturity", &T10, 0.001f, 1.0f, "%.5f");
        static float sigma10 = 0.0f;
        ImGui::InputFloat("implied volatility", &sigma10, 0.001f, 1.0f, "%.5f");
        static float TD10 = 0.0f;
        ImGui::InputFloat("TradeDays", &TD10, 1.0f, 100.0f, "%.1f");
        static float N10 = 0.0f;
        ImGui::InputFloat("Tree periods", &N10, 1.0f, 100.0f, "%.1f");
        ImGui::Text("");
        static bool checkcaculation1 = false;
        ImGui::Checkbox("start caculation", &checkcaculation1);
        float option_value1 = 0.0f;


        if (checkact1 && checkcaculation1) {
            // American call option tree
            ImGui::Text("Calculating... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            CRRBinomialTree tree(s10, T10, N10, sigma10, r10, q10, k10, 'C', A);
            option_value1 = tree.getOptionValue();
        }
        if (checkapt1 && checkcaculation1) {
            //"American put option tree", &checkapt
            ImGui::Text("Calculating... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            CRRBinomialTree tree(s10, T10, N10, sigma10, r10, q10, k10, 'P', A);
            option_value1 = tree.getOptionValue();
        }
        if (checkect1 && checkcaculation1) {
            //"European call option tree", &checkect
            ImGui::Text("Calculating... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            CRRBinomialTree tree(s10, T10, N10, sigma10, r10, q10, k10, 'C', E);
            option_value1 = tree.getOptionValue();
        }
        if (checkept1 && checkcaculation1) {
            //"European put option tree", &checkept
            ImGui::Text("Calculating... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            CRRBinomialTree tree(s10, T10, N10, sigma10, r10, q10, k10, 'P', E);
            option_value1 = tree.getOptionValue();
        }
        if (checklcm1 && checkcaculation1) {
            //"lookback call option M-C", &checklcm
            ImGui::Text("Calculating... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            Simulator* simulator = new Simulator(s10, r10, q10, T10, sigma10, 20, 10000, TD10);
            LookBack lookBackCall(simulator, 'C');
            option_value1 = lookBackCall.getMean();
        }
        if (checklpm1 && checkcaculation1) {
            //"lookback put option M-C", &checklpm
            ImGui::Text("Calculating... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            Simulator* simulator = new Simulator(s10, r10, q10, T10, sigma10, 20, 10000, TD10);
            LookBack lookBackCall(simulator, 'P');
            option_value1 = lookBackCall.getMean();
        }
        if (checkvcm1 && checkcaculation1) {
            //"vanilla call option M-C", &checkvcm
            ImGui::Text("Calculating... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            Simulator* simulator = new Simulator(s10, r10, q10, T10, sigma10, 20, 1000, TD10);
            VanillaOption vanillaCall(simulator, 'C', k10);
            option_value1 = vanillaCall.getMean();
        }
        if (checkvpm1 && checkcaculation1) {
            // "vanilla put option M-C", &checkvpm
            ImGui::Text("Calculating... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            Simulator* simulator = new Simulator(s10, r10, q10, T10, sigma10, 20, 1000, TD10);
            VanillaOption vanillaCall(simulator, 'P', k10);
            option_value1 = vanillaCall.getMean();
        }
        if (checkacm1 && checkcaculation1) {
            //Checkbox("Asian call option M-C", &checkacm
            ImGui::Text("Calculating... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            Simulator* simulator = new Simulator(s10, r10, q10, T10, sigma10, 20, 10000, TD10);
            AsianOption asianCall(simulator, 'C', k10);
            option_value1 = asianCall.getMean();
        }
        if (checkapm1 && checkcaculation1) {
            //"Asian put option M-C", &checkapm
            ImGui::Text("Calculating... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            Simulator* simulator = new Simulator(s10, r10, q10, T10, sigma10, 20, 10000, TD10);
            AsianOption asianCall(simulator, 'C', k10);
            option_value1 = asianCall.getMean();
        }


        ImGui::Text("");
        ImGui::Text("option value result: %.5f", option_value1);
        //checkcaculation = false;

        ImGui::End();
    };


    void renderui()
    {
        // ------------------------------------------------------------------------------------------------------
        // docking
        
        static bool opt_fullscreen = true;
        static bool opt_padding = false;
        static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

        // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
        // because it would be confusing to have two docking targets within each others.
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
        if (opt_fullscreen)
        {
            const ImGuiViewport* viewport = ImGui::GetMainViewport();
            ImGui::SetNextWindowPos(viewport->WorkPos);
            ImGui::SetNextWindowSize(viewport->WorkSize);
            ImGui::SetNextWindowViewport(viewport->ID);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
            window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
            window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
        }
        else
        {
            dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
        }

        // When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
        // and handle the pass-thru hole, so we ask Begin() to not render a background.
        if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
            window_flags |= ImGuiWindowFlags_NoBackground;

        // Important: note that we proceed even if Begin() returns false (aka window is collapsed).
        // This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
        // all active windows docked into it will lose their parent and become undocked.
        // We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
        // any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
        if (!opt_padding)
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
        ImGui::Begin("DockSpace Demo",nullptr, window_flags);
        if (!opt_padding)
            ImGui::PopStyleVar();

        if (opt_fullscreen)
            ImGui::PopStyleVar(2);

        // Submit the DockSpace
        ImGuiIO& io = ImGui::GetIO();
        if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
        {
            ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
            ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
        }


        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("Screen Docking"))
            {
                // Disabling fullscreen would allow the window to be moved to the front of other windows,
                // which we can't undo at the moment without finer window depth/z control.
                ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen);
                ImGui::MenuItem("Padding", NULL, &opt_padding);
                ImGui::Separator();

                if (ImGui::MenuItem("Flag: NoSplit", "", (dockspace_flags & ImGuiDockNodeFlags_NoSplit) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_NoSplit; }
                if (ImGui::MenuItem("Flag: NoResize", "", (dockspace_flags & ImGuiDockNodeFlags_NoResize) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_NoResize; }
                if (ImGui::MenuItem("Flag: NoDockingInCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_NoDockingInCentralNode) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_NoDockingInCentralNode; }
                if (ImGui::MenuItem("Flag: AutoHideTabBar", "", (dockspace_flags & ImGuiDockNodeFlags_AutoHideTabBar) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_AutoHideTabBar; }
                if (ImGui::MenuItem("Flag: PassthruCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode) != 0, opt_fullscreen)) { dockspace_flags ^= ImGuiDockNodeFlags_PassthruCentralNode; }
                ImGui::Separator();
                ImGui::EndMenu();
            }

            ImGui::EndMenuBar();
        }
        // ------------------------------------------------------------------------------------------------------
        // menu bar

        // ------------------------------------------------------------------------------------------------------
        //

        //
        //

 
        static bool checkact = false;
        static bool checkapt = false;
        static bool checkect = false;
        static bool checkept = false;
        static bool checklcm = false;
        static bool checklpm = false;
        static bool checkvcm = false;
        static bool checkvpm = false;
        static bool checkacm = false;
        static bool checkapm = false;

        static bool check3 = false;
        static bool check4 = false;
        static bool check5 = false;
        ImGui::Begin("main console");// Create a window called "Hello, world!" and append into it.
        ImGui::Text("We have two different methods, CRR binomial tree and Monte-Carlo Simutaions");
        ImGui::Text("All tree methods are vanilla options");
        ImGui::Text("All  Monte-Carlo methods are European options");
        ImGui::Text("option types:");
        //ImGui::Text("Loading %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
        ImGui::Text("");
        ImGui::Checkbox("American call option tree",&checkact);
        ImGui::Checkbox("American put option tree", &checkapt);
        ImGui::Checkbox("European call option tree", &checkect);
        ImGui::Checkbox("European put option tree", &checkept);

        ImGui::Checkbox("lookback call option M-C", &checklcm);
        ImGui::Checkbox("lookback put option M-C", &checklpm);

        ImGui::Checkbox("vanilla call option M-C", &checkvcm);
        ImGui::Checkbox("vanilla put option M-C", &checkvpm);

        ImGui::Checkbox("Asian call option M-C", &checkacm);
        ImGui::Checkbox("Asian put option M-C", &checkapm);

        ImGui::Separator();
        ImGui::Text("You can change parameters by clicking or typing ");
        ImGui::Text("parameter inputs:");
        ImGui::Text("");

        static float s0 = 0.0f;
        ImGui::InputFloat("Stock price", &s0, 0.001f, 1.0f, "%.5f");
        static float k0 = 0.0f;
        ImGui::InputFloat("Strike price", &k0, 0.001f, 1.0f, "%.5f");
        static float r0 = 0.0f;
        ImGui::InputFloat("risk-free-rate", &r0, 0.001f, 1.0f, "%.5f");
        static float q0 = 0.0f;
        ImGui::InputFloat("dividend", &q0, 0.001f, 1.0f, "%.5f");
        static float T0 = 0.0f;
        ImGui::InputFloat("Time to maturity", &T0, 0.001f, 1.0f, "%.5f");
        static float sigma0 = 0.0f;
        ImGui::InputFloat("implied volatility", &sigma0, 0.001f, 1.0f, "%.5f");
        static float TD0 = 0.0f;
        ImGui::InputFloat("TradeDays", &TD0, 1.0f, 100.0f, "%.1f");
        static float N0 = 0.0f;
        ImGui::InputFloat("Tree periods", &N0, 1.0f, 100.0f, "%.1f");

   
        ImGui::Text("");
        static bool checkcaculation = false;
        ImGui::Checkbox("start calculation", &checkcaculation);

        //Simulator(double S, double r,double q, double T, double sigma, int Rep, int Sim, int TradeDays)
        // s0,r0,q0,T0,sigma0,
        //CRRBinomialTree(const double s, const double t, const int n, const double sigma, const double r, const double q, const double k, const char whichOption, OptionType type)
        //

        float option_value = 0.0f;

        if (checkact && checkcaculation) {
            // American call option tree
            ImGui::Text("Calculating... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            CRRBinomialTree tree(s0, T0, N0, sigma0, r0, q0, k0, 'C', A);
            option_value = tree.getOptionValue();
        }
        if (checkapt && checkcaculation) {
            //"American put option tree", &checkapt
            ImGui::Text("Calculating... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            CRRBinomialTree tree(s0, T0, N0, sigma0, r0, q0, k0, 'P', A);
            option_value = tree.getOptionValue();
        }
        if (checkect && checkcaculation) {
            //"European call option tree", &checkect
            ImGui::Text("Calculating... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            CRRBinomialTree tree(s0, T0, N0, sigma0, r0, q0, k0, 'C', E);
            option_value = tree.getOptionValue();
        }
        if (checkept && checkcaculation) {
            //"European put option tree", &checkept
            ImGui::Text("Calculating... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            CRRBinomialTree tree(s0, T0, N0, sigma0, r0, q0, k0, 'P', E);
            option_value = tree.getOptionValue();
        }
        if (checklcm && checkcaculation) {
            //"lookback call option M-C", &checklcm
            ImGui::Text("Calculating... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            Simulator* simulator = new Simulator(s0, r0, q0, T0, sigma0, 20, 10000, TD0);
            LookBack lookBackCall(simulator, 'C');
            option_value = lookBackCall.getMean(); 
        }
        if (checklpm && checkcaculation) {
            //"lookback put option M-C", &checklpm
            ImGui::Text("Calculating... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            Simulator* simulator = new Simulator(s0, r0, q0, T0, sigma0, 20, 10000, TD0);
            LookBack lookBackCall(simulator, 'P');
            option_value = lookBackCall.getMean();
        }
        if (checkvcm && checkcaculation) {
            //"vanilla call option M-C", &checkvcm
            ImGui::Text("Calculating... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            Simulator* simulator = new Simulator(s0, r0, q0, T0, sigma0, 20, 1000, TD0);
            VanillaOption vanillaCall(simulator, 'C', k0);
            option_value = vanillaCall.getMean();
        }
        if (checkvpm && checkcaculation) {
            // "vanilla put option M-C", &checkvpm
            ImGui::Text("Calculating... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            Simulator* simulator = new Simulator(s0, r0, q0, T0, sigma0, 20, 1000, TD0);
            VanillaOption vanillaCall(simulator, 'P', k0);
            option_value = vanillaCall.getMean();
        }
        if (checkacm && checkcaculation) {
            //Checkbox("Asian call option M-C", &checkacm
            ImGui::Text("Calculating... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            Simulator* simulator = new Simulator(s0, r0, q0, T0, sigma0, 20, 10000, TD0);
            AsianOption asianCall(simulator, 'C', k0);
            option_value = asianCall.getMean();
        }
        if (checkapm && checkcaculation) {
            //"Asian put option M-C", &checkapm
            ImGui::Text("Calculating... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            Simulator* simulator = new Simulator(s0, r0, q0, T0, sigma0, 20, 10000, TD0);
            AsianOption asianCall(simulator, 'C', k0);
            option_value = asianCall.getMean();
        }


        ImGui::Text("");
        ImGui::Text("option value result: %.5f",option_value);
        //checkcaculation = false;
        ImGui::Separator();
        ImGui::Text("If you want to open a new window to compare different option values");
        ImGui::Text("Click the buttons below");

        ImGui::Text("");
        ImGui::Checkbox("create new window", &check3);

        if (check3) {
            newwindow1();
        }
        ImGui::End();
        
        ImGui::End();
    }
    
}
