using Test
using Serialization

push!(LOAD_PATH, "$(@__DIR__)/build")
using TestAutoAdd

function runtest()
    @testset "Automatic type wrapping" begin
    
        b1 = TestAutoAdd.B1()
        @test isa(TestAutoAdd.f(b1), TestAutoAdd.B2)
    
        a = TestAutoAdd.A()
        b3 = TestAutoAdd.B3()
        @test isa(f(a, b3), TestAutoAdd.B4)
    end
end

if "-s" in ARGS #Serialize mode
    Test.TESTSET_PRINT_ENABLE[] = false
    serialize(stdout, runtest())
else
    runtest()
end

