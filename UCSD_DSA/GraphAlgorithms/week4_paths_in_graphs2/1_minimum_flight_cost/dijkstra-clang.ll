; ModuleID = 'dijkstra.cpp'
source_filename = "dijkstra.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%"class.std::ios_base::Init" = type { i8 }
%"class.std::basic_ostream" = type { i32 (...)**, %"class.std::basic_ios" }
%"class.std::basic_ios" = type { %"class.std::ios_base", %"class.std::basic_ostream"*, i8, i8, %"class.std::basic_streambuf"*, %"class.std::ctype"*, %"class.std::num_put"*, %"class.std::num_get"* }
%"class.std::ios_base" = type { i32 (...)**, i64, i64, i32, i32, i32, %"struct.std::ios_base::_Callback_list"*, %"struct.std::ios_base::_Words", [8 x %"struct.std::ios_base::_Words"], i32, %"struct.std::ios_base::_Words"*, %"class.std::locale" }
%"struct.std::ios_base::_Callback_list" = type { %"struct.std::ios_base::_Callback_list"*, void (i32, %"class.std::ios_base"*, i32)*, i32, i32 }
%"struct.std::ios_base::_Words" = type { i8*, i64 }
%"class.std::locale" = type { %"class.std::locale::_Impl"* }
%"class.std::locale::_Impl" = type { i32, %"class.std::locale::facet"**, i64, %"class.std::locale::facet"**, i8** }
%"class.std::locale::facet" = type <{ i32 (...)**, i32, [4 x i8] }>
%"class.std::basic_streambuf" = type { i32 (...)**, i8*, i8*, i8*, i8*, i8*, i8*, %"class.std::locale" }
%"class.std::ctype" = type <{ %"class.std::locale::facet.base", [4 x i8], %struct.__locale_struct*, i8, [7 x i8], i32*, i32*, i16*, i8, [256 x i8], [256 x i8], i8, [6 x i8] }>
%"class.std::locale::facet.base" = type <{ i32 (...)**, i32 }>
%struct.__locale_struct = type { [13 x %struct.__locale_data*], i16*, i32*, i32*, [13 x i8*] }
%struct.__locale_data = type opaque
%"class.std::num_put" = type { %"class.std::locale::facet.base", [4 x i8] }
%"class.std::num_get" = type { %"class.std::locale::facet.base", [4 x i8] }
%"class.std::basic_istream" = type { i32 (...)**, i64, %"class.std::basic_ios" }
%"class.std::vector" = type { %"struct.std::_Bvector_base" }
%"struct.std::_Bvector_base" = type { %"struct.std::_Bvector_base<std::allocator<bool> >::_Bvector_impl" }
%"struct.std::_Bvector_base<std::allocator<bool> >::_Bvector_impl" = type { %"struct.std::_Bvector_base<std::allocator<bool> >::_Bvector_impl_data" }
%"struct.std::_Bvector_base<std::allocator<bool> >::_Bvector_impl_data" = type { %"struct.std::_Bit_iterator", %"struct.std::_Bit_iterator", i64* }
%"struct.std::_Bit_iterator" = type { %"struct.std::_Bit_iterator_base.base", [4 x i8] }
%"struct.std::_Bit_iterator_base.base" = type <{ i64*, i32 }>
%"class.std::vector.0" = type { %"struct.std::_Vector_base" }
%"struct.std::_Vector_base" = type { %"struct.std::_Vector_base<long long, std::allocator<long long> >::_Vector_impl" }
%"struct.std::_Vector_base<long long, std::allocator<long long> >::_Vector_impl" = type { %"struct.std::_Vector_base<long long, std::allocator<long long> >::_Vector_impl_data" }
%"struct.std::_Vector_base<long long, std::allocator<long long> >::_Vector_impl_data" = type { i64*, i64*, i64* }
%"class.std::vector.4" = type { %"struct.std::_Vector_base.5" }
%"struct.std::_Vector_base.5" = type { %"struct.std::_Vector_base<std::vector<std::pair<int, long long>, std::allocator<std::pair<int, long long> > >, std::allocator<std::vector<std::pair<int, long long>, std::allocator<std::pair<int, long long> > > > >::_Vector_impl" }
%"struct.std::_Vector_base<std::vector<std::pair<int, long long>, std::allocator<std::pair<int, long long> > >, std::allocator<std::vector<std::pair<int, long long>, std::allocator<std::pair<int, long long> > > > >::_Vector_impl" = type { %"struct.std::_Vector_base<std::vector<std::pair<int, long long>, std::allocator<std::pair<int, long long> > >, std::allocator<std::vector<std::pair<int, long long>, std::allocator<std::pair<int, long long> > > > >::_Vector_impl_data" }
%"struct.std::_Vector_base<std::vector<std::pair<int, long long>, std::allocator<std::pair<int, long long> > >, std::allocator<std::vector<std::pair<int, long long>, std::allocator<std::pair<int, long long> > > > >::_Vector_impl_data" = type { %"class.std::vector.9"*, %"class.std::vector.9"*, %"class.std::vector.9"* }
%"class.std::vector.9" = type { %"struct.std::_Vector_base.10" }
%"struct.std::_Vector_base.10" = type { %"struct.std::_Vector_base<std::pair<int, long long>, std::allocator<std::pair<int, long long> > >::_Vector_impl" }
%"struct.std::_Vector_base<std::pair<int, long long>, std::allocator<std::pair<int, long long> > >::_Vector_impl" = type { %"struct.std::_Vector_base<std::pair<int, long long>, std::allocator<std::pair<int, long long> > >::_Vector_impl_data" }
%"struct.std::_Vector_base<std::pair<int, long long>, std::allocator<std::pair<int, long long> > >::_Vector_impl_data" = type { %"struct.std::pair"*, %"struct.std::pair"*, %"struct.std::pair"* }
%"struct.std::pair" = type { i32, i64 }
%"class.std::priority_queue" = type <{ %"class.std::vector.14", %"struct.std::greater", [7 x i8] }>
%"class.std::vector.14" = type { %"struct.std::_Vector_base.15" }
%"struct.std::_Vector_base.15" = type { %"struct.std::_Vector_base<std::pair<long long, int>, std::allocator<std::pair<long long, int> > >::_Vector_impl" }
%"struct.std::_Vector_base<std::pair<long long, int>, std::allocator<std::pair<long long, int> > >::_Vector_impl" = type { %"struct.std::_Vector_base<std::pair<long long, int>, std::allocator<std::pair<long long, int> > >::_Vector_impl_data" }
%"struct.std::_Vector_base<std::pair<long long, int>, std::allocator<std::pair<long long, int> > >::_Vector_impl_data" = type { %"struct.std::pair.19"*, %"struct.std::pair.19"*, %"struct.std::pair.19"* }
%"struct.std::pair.19" = type <{ i64, i32, [4 x i8] }>
%"struct.std::greater" = type { i8 }

$_ZNSt14priority_queueISt4pairIxiESt6vectorIS1_SaIS1_EESt7greaterIS1_EE4pushEOS1_ = comdat any

$_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIxiESt6vectorIS3_SaIS3_EEEElS3_NS0_5__ops15_Iter_comp_iterISt7greaterIS3_EEEEvT_T0_SF_T1_T2_ = comdat any

@_ZStL8__ioinit = internal global %"class.std::ios_base::Init" zeroinitializer, align 1
@__dso_handle = external hidden global i8
@_ZSt4cout = external dso_local global %"class.std::basic_ostream", align 8
@.str = private unnamed_addr constant [2 x i8] c" \00", align 1
@_ZSt3cin = external dso_local global %"class.std::basic_istream", align 8
@.str.1 = private unnamed_addr constant [25 x i8] c"Time taken by function: \00", align 1
@.str.2 = private unnamed_addr constant [13 x i8] c" nanoseconds\00", align 1
@.str.3 = private unnamed_addr constant [26 x i8] c"vector::_M_realloc_insert\00", align 1
@.str.4 = private unnamed_addr constant [49 x i8] c"cannot create std::vector larger than max_size()\00", align 1
@llvm.global_ctors = appending global [1 x { i32, void ()*, i8* }] [{ i32, void ()*, i8* } { i32 65535, void ()* @_GLOBAL__sub_I_dijkstra.cpp, i8* null }]

declare dso_local void @_ZNSt8ios_base4InitC1Ev(%"class.std::ios_base::Init"*) unnamed_addr #0

; Function Attrs: nounwind
declare dso_local void @_ZNSt8ios_base4InitD1Ev(%"class.std::ios_base::Init"*) unnamed_addr #1

; Function Attrs: nofree nounwind
declare dso_local i32 @__cxa_atexit(void (i8*)*, i8*, i8*) local_unnamed_addr #2

; Function Attrs: uwtable
define dso_local void @_Z14NaiveAlgorithmiiRSt6vectorIbSaIbEERS_IxSaIxEERS_IS_ISt4pairIixESaIS7_EESaIS9_EEi(i32 %0, i32 %1, %"class.std::vector"* nocapture readonly dereferenceable(40) %2, %"class.std::vector.0"* nocapture readonly dereferenceable(24) %3, %"class.std::vector.4"* nocapture readonly dereferenceable(24) %4, i32 %5) local_unnamed_addr #3 {
  %7 = alloca i8, align 1
  %8 = sext i32 %0 to i64
  %9 = getelementptr inbounds %"class.std::vector.0", %"class.std::vector.0"* %3, i64 0, i32 0, i32 0, i32 0, i32 0
  %10 = load i64*, i64** %9, align 8, !tbaa !2
  %11 = getelementptr inbounds i64, i64* %10, i64 %8
  store i64 0, i64* %11, align 8, !tbaa !7
  %12 = getelementptr inbounds %"class.std::vector.4", %"class.std::vector.4"* %4, i64 0, i32 0, i32 0, i32 0, i32 0
  %13 = load %"class.std::vector.9"*, %"class.std::vector.9"** %12, align 8
  %14 = getelementptr %"class.std::vector", %"class.std::vector"* %2, i64 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0
  %15 = load i64*, i64** %14, align 8
  br label %16

16:                                               ; preds = %92, %6
  %17 = phi i32 [ %0, %6 ], [ %93, %92 ]
  %18 = icmp eq i32 %17, %1
  br i1 %18, label %136, label %19

19:                                               ; preds = %16
  %20 = sext i32 %17 to i64
  %21 = getelementptr inbounds %"class.std::vector.9", %"class.std::vector.9"* %13, i64 %20, i32 0, i32 0, i32 0, i32 0
  %22 = load %"struct.std::pair"*, %"struct.std::pair"** %21, align 8, !tbaa !9
  %23 = ptrtoint %"struct.std::pair"* %22 to i64
  %24 = getelementptr inbounds %"class.std::vector.9", %"class.std::vector.9"* %13, i64 %20, i32 0, i32 0, i32 0, i32 1
  %25 = load %"struct.std::pair"*, %"struct.std::pair"** %24, align 8, !tbaa !9
  %26 = icmp eq %"struct.std::pair"* %22, %25
  br i1 %26, label %129, label %27

27:                                               ; preds = %19
  %28 = getelementptr inbounds i64, i64* %10, i64 %20
  br label %46

29:                                               ; preds = %67
  %30 = lshr i64 %20, 6
  %31 = getelementptr inbounds i64, i64* %15, i64 %30
  %32 = and i64 %20, 63
  %33 = shl nuw i64 1, %32
  %34 = load i64, i64* %31, align 8, !tbaa !10
  %35 = or i64 %34, %33
  store i64 %35, i64* %31, align 8, !tbaa !10
  br i1 %26, label %136, label %36

36:                                               ; preds = %29
  %37 = getelementptr %"struct.std::pair", %"struct.std::pair"* %25, i64 -1
  %38 = ptrtoint %"struct.std::pair"* %37 to i64
  %39 = sub i64 %38, %23
  %40 = lshr i64 %39, 4
  %41 = add nuw nsw i64 %40, 1
  %42 = and i64 %41, 1
  %43 = icmp eq i64 %40, 0
  br i1 %43, label %70, label %44

44:                                               ; preds = %36
  %45 = sub nuw nsw i64 %41, %42
  br label %95

46:                                               ; preds = %27, %67
  %47 = phi %"struct.std::pair"* [ %22, %27 ], [ %68, %67 ]
  %48 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %47, i64 0, i32 0
  %49 = load i32, i32* %48, align 8, !tbaa !12
  %50 = sext i32 %49 to i64
  %51 = lshr i64 %50, 6
  %52 = getelementptr inbounds i64, i64* %15, i64 %51
  %53 = and i64 %50, 63
  %54 = shl nuw i64 1, %53
  %55 = load i64, i64* %52, align 8, !tbaa !10
  %56 = and i64 %54, %55
  %57 = icmp eq i64 %56, 0
  br i1 %57, label %58, label %67

58:                                               ; preds = %46
  %59 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %47, i64 0, i32 1
  %60 = load i64, i64* %59, align 8, !tbaa !15
  %61 = load i64, i64* %28, align 8, !tbaa !7
  %62 = add nsw i64 %61, %60
  %63 = getelementptr inbounds i64, i64* %10, i64 %50
  %64 = load i64, i64* %63, align 8, !tbaa !7
  %65 = icmp slt i64 %62, %64
  br i1 %65, label %66, label %67

66:                                               ; preds = %58
  store i64 %62, i64* %63, align 8, !tbaa !7
  br label %67

67:                                               ; preds = %46, %58, %66
  %68 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %47, i64 1
  %69 = icmp eq %"struct.std::pair"* %68, %25
  br i1 %69, label %29, label %46

70:                                               ; preds = %160, %36
  %71 = phi i32 [ undef, %36 ], [ %161, %160 ]
  %72 = phi i64 [ 1000000007, %36 ], [ %162, %160 ]
  %73 = phi i32 [ -1, %36 ], [ %161, %160 ]
  %74 = phi %"struct.std::pair"* [ %22, %36 ], [ %163, %160 ]
  %75 = icmp eq i64 %42, 0
  br i1 %75, label %92, label %76

76:                                               ; preds = %70
  %77 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %74, i64 0, i32 0
  %78 = load i32, i32* %77, align 8, !tbaa !12
  %79 = sext i32 %78 to i64
  %80 = lshr i64 %79, 6
  %81 = getelementptr inbounds i64, i64* %15, i64 %80
  %82 = and i64 %79, 63
  %83 = shl nuw i64 1, %82
  %84 = load i64, i64* %81, align 8, !tbaa !10
  %85 = and i64 %83, %84
  %86 = icmp eq i64 %85, 0
  br i1 %86, label %87, label %92

87:                                               ; preds = %76
  %88 = getelementptr inbounds i64, i64* %10, i64 %79
  %89 = load i64, i64* %88, align 8, !tbaa !7
  %90 = icmp slt i64 %89, %72
  %91 = select i1 %90, i32 %78, i32 %73
  br label %92

92:                                               ; preds = %87, %76, %70
  %93 = phi i32 [ %71, %70 ], [ %73, %76 ], [ %91, %87 ]
  %94 = icmp eq i32 %93, -1
  br i1 %94, label %136, label %16

95:                                               ; preds = %160, %44
  %96 = phi i64 [ 1000000007, %44 ], [ %162, %160 ]
  %97 = phi i32 [ -1, %44 ], [ %161, %160 ]
  %98 = phi %"struct.std::pair"* [ %22, %44 ], [ %163, %160 ]
  %99 = phi i64 [ %45, %44 ], [ %164, %160 ]
  %100 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %98, i64 0, i32 0
  %101 = load i32, i32* %100, align 8, !tbaa !12
  %102 = sext i32 %101 to i64
  %103 = lshr i64 %102, 6
  %104 = getelementptr inbounds i64, i64* %15, i64 %103
  %105 = and i64 %102, 63
  %106 = shl nuw i64 1, %105
  %107 = load i64, i64* %104, align 8, !tbaa !10
  %108 = and i64 %106, %107
  %109 = icmp eq i64 %108, 0
  br i1 %109, label %110, label %116

110:                                              ; preds = %95
  %111 = getelementptr inbounds i64, i64* %10, i64 %102
  %112 = load i64, i64* %111, align 8, !tbaa !7
  %113 = icmp slt i64 %112, %96
  %114 = select i1 %113, i32 %101, i32 %97
  %115 = select i1 %113, i64 %112, i64 %96
  br label %116

116:                                              ; preds = %95, %110
  %117 = phi i32 [ %97, %95 ], [ %114, %110 ]
  %118 = phi i64 [ %96, %95 ], [ %115, %110 ]
  %119 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %98, i64 1, i32 0
  %120 = load i32, i32* %119, align 8, !tbaa !12
  %121 = sext i32 %120 to i64
  %122 = lshr i64 %121, 6
  %123 = getelementptr inbounds i64, i64* %15, i64 %122
  %124 = and i64 %121, 63
  %125 = shl nuw i64 1, %124
  %126 = load i64, i64* %123, align 8, !tbaa !10
  %127 = and i64 %125, %126
  %128 = icmp eq i64 %127, 0
  br i1 %128, label %154, label %160

129:                                              ; preds = %19
  %130 = lshr i64 %20, 6
  %131 = getelementptr inbounds i64, i64* %15, i64 %130
  %132 = and i64 %20, 63
  %133 = shl nuw i64 1, %132
  %134 = load i64, i64* %131, align 8, !tbaa !10
  %135 = or i64 %134, %133
  store i64 %135, i64* %131, align 8, !tbaa !10
  br label %136

136:                                              ; preds = %29, %92, %16, %129
  %137 = icmp slt i32 %5, 1
  br i1 %137, label %141, label %138

138:                                              ; preds = %136
  %139 = add nuw i32 %5, 1
  %140 = zext i32 %139 to i64
  br label %142

141:                                              ; preds = %142, %136
  ret void

142:                                              ; preds = %142, %138
  %143 = phi i64 [ 1, %138 ], [ %152, %142 ]
  %144 = trunc i64 %143 to i32
  %145 = call dereferenceable(272) %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"* nonnull @_ZSt4cout, i32 %144)
  %146 = call dereferenceable(272) %"class.std::basic_ostream"* @_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l(%"class.std::basic_ostream"* nonnull dereferenceable(272) %145, i8* nonnull getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i64 0, i64 0), i64 1)
  %147 = load i64*, i64** %9, align 8, !tbaa !2
  %148 = getelementptr inbounds i64, i64* %147, i64 %143
  %149 = load i64, i64* %148, align 8, !tbaa !7
  %150 = call dereferenceable(272) %"class.std::basic_ostream"* @_ZNSo9_M_insertIxEERSoT_(%"class.std::basic_ostream"* nonnull %145, i64 %149)
  call void @llvm.lifetime.start.p0i8(i64 1, i8* nonnull %7)
  store i8 10, i8* %7, align 1, !tbaa !16
  %151 = call dereferenceable(272) %"class.std::basic_ostream"* @_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l(%"class.std::basic_ostream"* nonnull dereferenceable(272) %150, i8* nonnull %7, i64 1)
  call void @llvm.lifetime.end.p0i8(i64 1, i8* nonnull %7)
  %152 = add nuw nsw i64 %143, 1
  %153 = icmp eq i64 %152, %140
  br i1 %153, label %141, label %142

154:                                              ; preds = %116
  %155 = getelementptr inbounds i64, i64* %10, i64 %121
  %156 = load i64, i64* %155, align 8, !tbaa !7
  %157 = icmp slt i64 %156, %118
  %158 = select i1 %157, i32 %120, i32 %117
  %159 = select i1 %157, i64 %156, i64 %118
  br label %160

160:                                              ; preds = %154, %116
  %161 = phi i32 [ %117, %116 ], [ %158, %154 ]
  %162 = phi i64 [ %118, %116 ], [ %159, %154 ]
  %163 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %98, i64 2
  %164 = add i64 %99, -2
  %165 = icmp eq i64 %164, 0
  br i1 %165, label %70, label %95
}

; Function Attrs: argmemonly nounwind willreturn
declare void @llvm.lifetime.start.p0i8(i64 immarg, i8* nocapture) #4

; Function Attrs: argmemonly nounwind willreturn
declare void @llvm.lifetime.end.p0i8(i64 immarg, i8* nocapture) #4

declare dso_local dereferenceable(272) %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"*, i32) local_unnamed_addr #0

; Function Attrs: uwtable
define dso_local void @_Z18OptimizedAlgorithmiiRSt6vectorIbSaIbEERS_IxSaIxEERS_IS_ISt4pairIixESaIS7_EESaIS9_EE(i32 %0, i32 %1, %"class.std::vector"* nocapture readonly dereferenceable(40) %2, %"class.std::vector.0"* nocapture readonly dereferenceable(24) %3, %"class.std::vector.4"* nocapture readonly dereferenceable(24) %4) local_unnamed_addr #3 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %6 = alloca %"class.std::priority_queue", align 8
  %7 = alloca %"struct.std::pair.19", align 8
  %8 = alloca %"struct.std::pair.19", align 8
  %9 = sext i32 %0 to i64
  %10 = getelementptr inbounds %"class.std::vector.0", %"class.std::vector.0"* %3, i64 0, i32 0, i32 0, i32 0, i32 0
  %11 = load i64*, i64** %10, align 8, !tbaa !2
  %12 = getelementptr inbounds i64, i64* %11, i64 %9
  store i64 0, i64* %12, align 8, !tbaa !7
  %13 = bitcast %"class.std::priority_queue"* %6 to i8*
  call void @llvm.lifetime.start.p0i8(i64 32, i8* nonnull %13) #9
  call void @llvm.memset.p0i8.i64(i8* nonnull align 8 dereferenceable(24) %13, i8 0, i64 24, i1 false) #9
  %14 = bitcast %"struct.std::pair.19"* %7 to i8*
  call void @llvm.lifetime.start.p0i8(i64 16, i8* nonnull %14) #9
  %15 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %7, i64 0, i32 0
  %16 = load i64, i64* %12, align 8, !tbaa !7
  store i64 %16, i64* %15, align 8, !tbaa !17
  %17 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %7, i64 0, i32 1
  store i32 %0, i32* %17, align 8, !tbaa !19
  invoke void @_ZNSt14priority_queueISt4pairIxiESt6vectorIS1_SaIS1_EESt7greaterIS1_EE4pushEOS1_(%"class.std::priority_queue"* nonnull %6, %"struct.std::pair.19"* nonnull dereferenceable(16) %7)
          to label %18 unwind label %66

18:                                               ; preds = %5
  call void @llvm.lifetime.end.p0i8(i64 16, i8* nonnull %14) #9
  %19 = getelementptr inbounds %"class.std::priority_queue", %"class.std::priority_queue"* %6, i64 0, i32 0, i32 0, i32 0, i32 0, i32 1
  %20 = bitcast %"struct.std::pair.19"** %19 to i64*
  %21 = load i64, i64* %20, align 8, !tbaa !20
  %22 = bitcast %"class.std::priority_queue"* %6 to i64*
  %23 = load i64, i64* %22, align 8, !tbaa !22
  %24 = icmp eq i64 %21, %23
  br i1 %24, label %132, label %25

25:                                               ; preds = %18
  %26 = getelementptr %"class.std::vector", %"class.std::vector"* %2, i64 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0
  %27 = getelementptr inbounds %"class.std::vector.4", %"class.std::vector.4"* %4, i64 0, i32 0, i32 0, i32 0, i32 0
  %28 = bitcast %"struct.std::pair.19"* %8 to i8*
  %29 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %8, i64 0, i32 0
  %30 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %8, i64 0, i32 1
  br label %31

31:                                               ; preds = %25, %128
  %32 = phi i64 [ %21, %25 ], [ %129, %128 ]
  %33 = phi i64 [ %23, %25 ], [ %130, %128 ]
  %34 = inttoptr i64 %33 to %"struct.std::pair.19"*
  %35 = inttoptr i64 %32 to %"struct.std::pair.19"*
  %36 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %34, i64 0, i32 0
  %37 = load i64, i64* %36, align 8
  %38 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %34, i64 0, i32 1
  %39 = load i32, i32* %38, align 8
  %40 = sub i64 %32, %33
  %41 = icmp sgt i64 %40, 16
  br i1 %41, label %42, label %53

42:                                               ; preds = %31
  %43 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %35, i64 -1
  %44 = ptrtoint %"struct.std::pair.19"* %43 to i64
  %45 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %43, i64 0, i32 0
  %46 = load i64, i64* %45, align 8
  %47 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %35, i64 -1, i32 1
  %48 = load i32, i32* %47, align 8
  store i64 %37, i64* %45, align 8, !tbaa !17
  store i32 %39, i32* %47, align 8, !tbaa !19
  %49 = sub i64 %44, %33
  %50 = ashr exact i64 %49, 4
  invoke void @_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIxiESt6vectorIS3_SaIS3_EEEElS3_NS0_5__ops15_Iter_comp_iterISt7greaterIS3_EEEEvT_T0_SF_T1_T2_(%"struct.std::pair.19"* %34, i64 0, i64 %50, i64 %46, i32 %48)
          to label %51 unwind label %74

51:                                               ; preds = %42
  %52 = load %"struct.std::pair.19"*, %"struct.std::pair.19"** %19, align 8, !tbaa !20
  br label %53

53:                                               ; preds = %31, %51
  %54 = phi %"struct.std::pair.19"* [ %35, %31 ], [ %52, %51 ]
  %55 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %54, i64 -1
  store %"struct.std::pair.19"* %55, %"struct.std::pair.19"** %19, align 8, !tbaa !20
  %56 = sext i32 %39 to i64
  %57 = load i64*, i64** %26, align 8, !tbaa !23
  %58 = lshr i64 %56, 6
  %59 = getelementptr inbounds i64, i64* %57, i64 %58
  %60 = and i64 %56, 63
  %61 = shl nuw i64 1, %60
  %62 = load i64, i64* %59, align 8, !tbaa !10
  %63 = and i64 %62, %61
  %64 = icmp eq i64 %63, 0
  %65 = ptrtoint %"struct.std::pair.19"* %55 to i64
  br i1 %64, label %78, label %128

66:                                               ; preds = %5
  %67 = landingpad { i8*, i32 }
          cleanup
  %68 = extractvalue { i8*, i32 } %67, 0
  %69 = extractvalue { i8*, i32 } %67, 1
  call void @llvm.lifetime.end.p0i8(i64 16, i8* nonnull %14) #9
  br label %147

70:                                               ; preds = %132
  %71 = landingpad { i8*, i32 }
          cleanup
  %72 = extractvalue { i8*, i32 } %71, 0
  %73 = extractvalue { i8*, i32 } %71, 1
  br label %147

74:                                               ; preds = %42
  %75 = landingpad { i8*, i32 }
          cleanup
  %76 = extractvalue { i8*, i32 } %75, 0
  %77 = extractvalue { i8*, i32 } %75, 1
  br label %147

78:                                               ; preds = %53
  %79 = load %"class.std::vector.9"*, %"class.std::vector.9"** %27, align 8, !tbaa !25
  %80 = getelementptr inbounds %"class.std::vector.9", %"class.std::vector.9"* %79, i64 %56, i32 0, i32 0, i32 0, i32 0
  %81 = load %"struct.std::pair"*, %"struct.std::pair"** %80, align 8, !tbaa !9
  %82 = getelementptr inbounds %"class.std::vector.9", %"class.std::vector.9"* %79, i64 %56, i32 0, i32 0, i32 0, i32 1
  %83 = load %"struct.std::pair"*, %"struct.std::pair"** %82, align 8, !tbaa !9
  %84 = icmp eq %"struct.std::pair"* %81, %83
  br i1 %84, label %128, label %85

85:                                               ; preds = %78, %121
  %86 = phi i64* [ %122, %121 ], [ %57, %78 ]
  %87 = phi i64* [ %123, %121 ], [ %57, %78 ]
  %88 = phi %"struct.std::pair"* [ %124, %121 ], [ %81, %78 ]
  %89 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %88, i64 0, i32 0
  %90 = load i32, i32* %89, align 8, !tbaa !12
  %91 = sext i32 %90 to i64
  %92 = lshr i64 %91, 6
  %93 = getelementptr inbounds i64, i64* %87, i64 %92
  %94 = and i64 %91, 63
  %95 = shl nuw i64 1, %94
  %96 = load i64, i64* %93, align 8, !tbaa !10
  %97 = and i64 %95, %96
  %98 = icmp eq i64 %97, 0
  br i1 %98, label %99, label %121

99:                                               ; preds = %85
  %100 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %88, i64 0, i32 1
  %101 = load i64, i64* %100, align 8, !tbaa !15
  %102 = shl i64 %101, 32
  %103 = ashr exact i64 %102, 32
  %104 = add nsw i64 %103, %37
  %105 = load i64*, i64** %10, align 8, !tbaa !2
  %106 = getelementptr inbounds i64, i64* %105, i64 %91
  %107 = load i64, i64* %106, align 8, !tbaa !7
  %108 = icmp slt i64 %104, %107
  br i1 %108, label %109, label %116

109:                                              ; preds = %99
  store i64 %104, i64* %106, align 8, !tbaa !7
  call void @llvm.lifetime.start.p0i8(i64 16, i8* nonnull %28) #9
  store i64 %104, i64* %29, align 8, !tbaa !17
  store i32 %90, i32* %30, align 8, !tbaa !19
  invoke void @_ZNSt14priority_queueISt4pairIxiESt6vectorIS1_SaIS1_EESt7greaterIS1_EE4pushEOS1_(%"class.std::priority_queue"* nonnull %6, %"struct.std::pair.19"* nonnull dereferenceable(16) %8)
          to label %110 unwind label %112

110:                                              ; preds = %109
  call void @llvm.lifetime.end.p0i8(i64 16, i8* nonnull %28) #9
  %111 = load i64*, i64** %26, align 8, !tbaa !23
  br label %116

112:                                              ; preds = %109
  %113 = landingpad { i8*, i32 }
          cleanup
  %114 = extractvalue { i8*, i32 } %113, 0
  %115 = extractvalue { i8*, i32 } %113, 1
  call void @llvm.lifetime.end.p0i8(i64 16, i8* nonnull %28) #9
  br label %147

116:                                              ; preds = %99, %110
  %117 = phi i64* [ %86, %99 ], [ %111, %110 ]
  %118 = getelementptr inbounds i64, i64* %117, i64 %58
  %119 = load i64, i64* %118, align 8, !tbaa !10
  %120 = or i64 %119, %61
  store i64 %120, i64* %118, align 8, !tbaa !10
  br label %121

121:                                              ; preds = %85, %116
  %122 = phi i64* [ %86, %85 ], [ %117, %116 ]
  %123 = phi i64* [ %87, %85 ], [ %117, %116 ]
  %124 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %88, i64 1
  %125 = icmp eq %"struct.std::pair"* %124, %83
  br i1 %125, label %126, label %85

126:                                              ; preds = %121
  %127 = load i64, i64* %20, align 8, !tbaa !20
  br label %128

128:                                              ; preds = %126, %78, %53
  %129 = phi i64 [ %127, %126 ], [ %65, %78 ], [ %65, %53 ]
  %130 = load i64, i64* %22, align 8, !tbaa !22
  %131 = icmp eq i64 %129, %130
  br i1 %131, label %132, label %31

132:                                              ; preds = %128, %18
  %133 = sext i32 %1 to i64
  %134 = load i64*, i64** %10, align 8, !tbaa !2
  %135 = getelementptr inbounds i64, i64* %134, i64 %133
  %136 = load i64, i64* %135, align 8, !tbaa !7
  %137 = icmp eq i64 %136, 1000000007
  %138 = select i1 %137, i64 -1, i64 %136
  %139 = invoke dereferenceable(272) %"class.std::basic_ostream"* @_ZNSo9_M_insertIxEERSoT_(%"class.std::basic_ostream"* nonnull @_ZSt4cout, i64 %138)
          to label %140 unwind label %70

140:                                              ; preds = %132
  %141 = getelementptr inbounds %"class.std::priority_queue", %"class.std::priority_queue"* %6, i64 0, i32 0, i32 0, i32 0, i32 0, i32 0
  %142 = load %"struct.std::pair.19"*, %"struct.std::pair.19"** %141, align 8, !tbaa !22
  %143 = icmp eq %"struct.std::pair.19"* %142, null
  br i1 %143, label %146, label %144

144:                                              ; preds = %140
  %145 = bitcast %"struct.std::pair.19"* %142 to i8*
  call void @_ZdlPv(i8* nonnull %145) #9
  br label %146

146:                                              ; preds = %140, %144
  call void @llvm.lifetime.end.p0i8(i64 32, i8* nonnull %13) #9
  ret void

147:                                              ; preds = %112, %74, %70, %66
  %148 = phi i32 [ %73, %70 ], [ %69, %66 ], [ %77, %74 ], [ %115, %112 ]
  %149 = phi i8* [ %72, %70 ], [ %68, %66 ], [ %76, %74 ], [ %114, %112 ]
  %150 = getelementptr inbounds %"class.std::priority_queue", %"class.std::priority_queue"* %6, i64 0, i32 0, i32 0, i32 0, i32 0, i32 0
  %151 = load %"struct.std::pair.19"*, %"struct.std::pair.19"** %150, align 8, !tbaa !22
  %152 = icmp eq %"struct.std::pair.19"* %151, null
  br i1 %152, label %155, label %153

153:                                              ; preds = %147
  %154 = bitcast %"struct.std::pair.19"* %151 to i8*
  call void @_ZdlPv(i8* nonnull %154) #9
  br label %155

155:                                              ; preds = %147, %153
  call void @llvm.lifetime.end.p0i8(i64 32, i8* nonnull %13) #9
  %156 = insertvalue { i8*, i32 } undef, i8* %149, 0
  %157 = insertvalue { i8*, i32 } %156, i32 %148, 1
  resume { i8*, i32 } %157
}

; Function Attrs: uwtable
define linkonce_odr dso_local void @_ZNSt14priority_queueISt4pairIxiESt6vectorIS1_SaIS1_EESt7greaterIS1_EE4pushEOS1_(%"class.std::priority_queue"* %0, %"struct.std::pair.19"* dereferenceable(16) %1) local_unnamed_addr #3 comdat align 2 personality i32 (...)* @__gxx_personality_v0 {
  %3 = getelementptr inbounds %"class.std::priority_queue", %"class.std::priority_queue"* %0, i64 0, i32 0, i32 0, i32 0, i32 0, i32 1
  %4 = load %"struct.std::pair.19"*, %"struct.std::pair.19"** %3, align 8, !tbaa !20
  %5 = getelementptr inbounds %"class.std::priority_queue", %"class.std::priority_queue"* %0, i64 0, i32 0, i32 0, i32 0, i32 0, i32 2
  %6 = load %"struct.std::pair.19"*, %"struct.std::pair.19"** %5, align 8, !tbaa !27
  %7 = icmp eq %"struct.std::pair.19"* %4, %6
  br i1 %7, label %15, label %8

8:                                                ; preds = %2
  %9 = bitcast %"struct.std::pair.19"* %4 to i8*
  %10 = bitcast %"struct.std::pair.19"* %1 to i8*
  tail call void @llvm.memcpy.p0i8.p0i8.i64(i8* nonnull align 8 dereferenceable(16) %9, i8* nonnull align 8 dereferenceable(16) %10, i64 16, i1 false) #9
  %11 = load %"struct.std::pair.19"*, %"struct.std::pair.19"** %3, align 8, !tbaa !20
  %12 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %11, i64 1
  store %"struct.std::pair.19"* %12, %"struct.std::pair.19"** %3, align 8, !tbaa !20
  %13 = getelementptr inbounds %"class.std::priority_queue", %"class.std::priority_queue"* %0, i64 0, i32 0, i32 0, i32 0, i32 0, i32 0
  %14 = load %"struct.std::pair.19"*, %"struct.std::pair.19"** %13, align 8, !tbaa !9
  br label %97

15:                                               ; preds = %2
  %16 = ptrtoint %"struct.std::pair.19"* %4 to i64
  %17 = bitcast %"class.std::priority_queue"* %0 to i64*
  %18 = load i64, i64* %17, align 8, !tbaa !22
  %19 = sub i64 %16, %18
  %20 = ashr exact i64 %19, 4
  %21 = icmp eq i64 %19, 9223372036854775792
  %22 = inttoptr i64 %18 to %"struct.std::pair.19"*
  br i1 %21, label %23, label %24

23:                                               ; preds = %15
  tail call void @_ZSt20__throw_length_errorPKc(i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str.3, i64 0, i64 0)) #10
  unreachable

24:                                               ; preds = %15
  %25 = icmp eq i64 %19, 0
  %26 = select i1 %25, i64 1, i64 %20
  %27 = add nsw i64 %26, %20
  %28 = icmp ult i64 %27, %20
  %29 = icmp ugt i64 %27, 576460752303423487
  %30 = or i1 %28, %29
  %31 = select i1 %30, i64 576460752303423487, i64 %27
  %32 = getelementptr inbounds %"class.std::priority_queue", %"class.std::priority_queue"* %0, i64 0, i32 0, i32 0, i32 0, i32 0, i32 0
  %33 = icmp eq i64 %31, 0
  br i1 %33, label %38, label %34

34:                                               ; preds = %24
  %35 = shl nuw nsw i64 %31, 4
  %36 = tail call i8* @_Znwm(i64 %35)
  %37 = bitcast i8* %36 to %"struct.std::pair.19"*
  br label %38

38:                                               ; preds = %34, %24
  %39 = phi %"struct.std::pair.19"* [ %37, %34 ], [ null, %24 ]
  %40 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %39, i64 %20
  %41 = bitcast %"struct.std::pair.19"* %40 to i8*
  %42 = bitcast %"struct.std::pair.19"* %1 to i8*
  tail call void @llvm.memcpy.p0i8.p0i8.i64(i8* nonnull align 8 dereferenceable(16) %41, i8* nonnull align 8 dereferenceable(16) %42, i64 16, i1 false) #9
  %43 = icmp eq %"struct.std::pair.19"* %4, %22
  br i1 %43, label %89, label %44

44:                                               ; preds = %38
  %45 = getelementptr %"struct.std::pair.19", %"struct.std::pair.19"* %4, i64 -1, i32 0
  %46 = bitcast i64* %45 to i8*
  %47 = sub i64 0, %18
  %48 = getelementptr i8, i8* %46, i64 %47
  %49 = ptrtoint i8* %48 to i64
  %50 = lshr i64 %49, 4
  %51 = add nuw nsw i64 %50, 1
  %52 = and i64 %51, 3
  %53 = icmp eq i64 %52, 0
  br i1 %53, label %64, label %54

54:                                               ; preds = %44, %54
  %55 = phi %"struct.std::pair.19"* [ %61, %54 ], [ %39, %44 ]
  %56 = phi %"struct.std::pair.19"* [ %60, %54 ], [ %22, %44 ]
  %57 = phi i64 [ %62, %54 ], [ %52, %44 ]
  %58 = bitcast %"struct.std::pair.19"* %55 to i8*
  %59 = bitcast %"struct.std::pair.19"* %56 to i8*
  tail call void @llvm.memcpy.p0i8.p0i8.i64(i8* nonnull align 8 dereferenceable(16) %58, i8* nonnull align 8 dereferenceable(16) %59, i64 16, i1 false) #9
  %60 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %56, i64 1
  %61 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %55, i64 1
  %62 = add i64 %57, -1
  %63 = icmp eq i64 %62, 0
  br i1 %63, label %64, label %54, !llvm.loop !28

64:                                               ; preds = %54, %44
  %65 = phi %"struct.std::pair.19"* [ undef, %44 ], [ %61, %54 ]
  %66 = phi %"struct.std::pair.19"* [ %39, %44 ], [ %61, %54 ]
  %67 = phi %"struct.std::pair.19"* [ %22, %44 ], [ %60, %54 ]
  %68 = icmp ult i8* %48, inttoptr (i64 48 to i8*)
  br i1 %68, label %89, label %69

69:                                               ; preds = %64, %69
  %70 = phi %"struct.std::pair.19"* [ %87, %69 ], [ %66, %64 ]
  %71 = phi %"struct.std::pair.19"* [ %86, %69 ], [ %67, %64 ]
  %72 = bitcast %"struct.std::pair.19"* %70 to i8*
  %73 = bitcast %"struct.std::pair.19"* %71 to i8*
  tail call void @llvm.memcpy.p0i8.p0i8.i64(i8* nonnull align 8 dereferenceable(16) %72, i8* nonnull align 8 dereferenceable(16) %73, i64 16, i1 false) #9
  %74 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %71, i64 1
  %75 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %70, i64 1
  %76 = bitcast %"struct.std::pair.19"* %75 to i8*
  %77 = bitcast %"struct.std::pair.19"* %74 to i8*
  tail call void @llvm.memcpy.p0i8.p0i8.i64(i8* nonnull align 8 dereferenceable(16) %76, i8* nonnull align 8 dereferenceable(16) %77, i64 16, i1 false) #9
  %78 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %71, i64 2
  %79 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %70, i64 2
  %80 = bitcast %"struct.std::pair.19"* %79 to i8*
  %81 = bitcast %"struct.std::pair.19"* %78 to i8*
  tail call void @llvm.memcpy.p0i8.p0i8.i64(i8* nonnull align 8 dereferenceable(16) %80, i8* nonnull align 8 dereferenceable(16) %81, i64 16, i1 false) #9
  %82 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %71, i64 3
  %83 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %70, i64 3
  %84 = bitcast %"struct.std::pair.19"* %83 to i8*
  %85 = bitcast %"struct.std::pair.19"* %82 to i8*
  tail call void @llvm.memcpy.p0i8.p0i8.i64(i8* nonnull align 8 dereferenceable(16) %84, i8* nonnull align 8 dereferenceable(16) %85, i64 16, i1 false) #9
  %86 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %71, i64 4
  %87 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %70, i64 4
  %88 = icmp eq %"struct.std::pair.19"* %86, %4
  br i1 %88, label %89, label %69

89:                                               ; preds = %64, %69, %38
  %90 = phi %"struct.std::pair.19"* [ %39, %38 ], [ %65, %64 ], [ %87, %69 ]
  %91 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %90, i64 1
  %92 = icmp eq i64 %18, 0
  br i1 %92, label %95, label %93

93:                                               ; preds = %89
  %94 = inttoptr i64 %18 to i8*
  tail call void @_ZdlPv(i8* nonnull %94) #9
  br label %95

95:                                               ; preds = %89, %93
  store %"struct.std::pair.19"* %39, %"struct.std::pair.19"** %32, align 8, !tbaa !22
  store %"struct.std::pair.19"* %91, %"struct.std::pair.19"** %3, align 8, !tbaa !20
  %96 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %39, i64 %31
  store %"struct.std::pair.19"* %96, %"struct.std::pair.19"** %5, align 8, !tbaa !27
  br label %97

97:                                               ; preds = %8, %95
  %98 = phi %"struct.std::pair.19"* [ %12, %8 ], [ %91, %95 ]
  %99 = phi %"struct.std::pair.19"* [ %14, %8 ], [ %39, %95 ]
  %100 = ptrtoint %"struct.std::pair.19"* %99 to i64
  %101 = ptrtoint %"struct.std::pair.19"* %98 to i64
  %102 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %98, i64 -1, i32 0
  %103 = load i64, i64* %102, align 8
  %104 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %98, i64 -1, i32 1
  %105 = load i32, i32* %104, align 8
  %106 = sub i64 %101, %100
  %107 = ashr exact i64 %106, 4
  %108 = add nsw i64 %107, -1
  %109 = icmp sgt i64 %106, 16
  br i1 %109, label %110, label %131

110:                                              ; preds = %97, %126
  %111 = phi i64 [ %113, %126 ], [ %108, %97 ]
  %112 = add nsw i64 %111, -1
  %113 = sdiv i64 %112, 2
  %114 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %99, i64 %113, i32 0
  %115 = load i64, i64* %114, align 8, !tbaa !17
  %116 = icmp sgt i64 %115, %103
  br i1 %116, label %117, label %120

117:                                              ; preds = %110
  %118 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %99, i64 %113, i32 1
  %119 = load i32, i32* %118, align 4, !tbaa !30
  br label %126

120:                                              ; preds = %110
  %121 = icmp slt i64 %115, %103
  br i1 %121, label %131, label %122

122:                                              ; preds = %120
  %123 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %99, i64 %113, i32 1
  %124 = load i32, i32* %123, align 8, !tbaa !19
  %125 = icmp sgt i32 %124, %105
  br i1 %125, label %126, label %131

126:                                              ; preds = %122, %117
  %127 = phi i32 [ %119, %117 ], [ %124, %122 ]
  %128 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %99, i64 %111, i32 0
  store i64 %115, i64* %128, align 8, !tbaa !17
  %129 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %99, i64 %111, i32 1
  store i32 %127, i32* %129, align 8, !tbaa !19
  %130 = icmp sgt i64 %111, 2
  br i1 %130, label %110, label %131

131:                                              ; preds = %120, %122, %126, %97
  %132 = phi i64 [ %108, %97 ], [ %111, %120 ], [ %113, %126 ], [ %111, %122 ]
  %133 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %99, i64 %132, i32 0
  store i64 %103, i64* %133, align 8, !tbaa !17
  %134 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %99, i64 %132, i32 1
  store i32 %105, i32* %134, align 8, !tbaa !19
  ret void
}

declare dso_local i32 @__gxx_personality_v0(...)

; Function Attrs: argmemonly nounwind willreturn
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* noalias nocapture writeonly, i8* noalias nocapture readonly, i64, i1 immarg) #4

; Function Attrs: norecurse uwtable
define dso_local i32 @main() local_unnamed_addr #5 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca %"class.std::vector.4", align 8
  %4 = alloca %"class.std::vector", align 8
  %5 = alloca %"class.std::vector.0", align 8
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i64, align 8
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = tail call zeroext i1 @_ZNSt8ios_base15sync_with_stdioEb(i1 zeroext false)
  %12 = load i8*, i8** bitcast (%"class.std::basic_istream"* @_ZSt3cin to i8**), align 8, !tbaa !31
  %13 = getelementptr i8, i8* %12, i64 -24
  %14 = bitcast i8* %13 to i64*
  %15 = load i64, i64* %14, align 8
  %16 = getelementptr inbounds i8, i8* bitcast (%"class.std::basic_istream"* @_ZSt3cin to i8*), i64 %15
  %17 = getelementptr inbounds i8, i8* %16, i64 216
  %18 = bitcast i8* %17 to %"class.std::basic_ostream"**
  store %"class.std::basic_ostream"* null, %"class.std::basic_ostream"** %18, align 8, !tbaa !33
  %19 = load i8*, i8** bitcast (%"class.std::basic_ostream"* @_ZSt4cout to i8**), align 8, !tbaa !31
  %20 = getelementptr i8, i8* %19, i64 -24
  %21 = bitcast i8* %20 to i64*
  %22 = load i64, i64* %21, align 8
  %23 = getelementptr inbounds i8, i8* bitcast (%"class.std::basic_ostream"* @_ZSt4cout to i8*), i64 %22
  %24 = getelementptr inbounds i8, i8* %23, i64 216
  %25 = bitcast i8* %24 to %"class.std::basic_ostream"**
  store %"class.std::basic_ostream"* null, %"class.std::basic_ostream"** %25, align 8, !tbaa !33
  %26 = bitcast i32* %1 to i8*
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %26) #9
  %27 = bitcast i32* %2 to i8*
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %27) #9
  %28 = call dereferenceable(280) %"class.std::basic_istream"* @_ZNSirsERi(%"class.std::basic_istream"* nonnull @_ZSt3cin, i32* nonnull dereferenceable(4) %1)
  %29 = call dereferenceable(280) %"class.std::basic_istream"* @_ZNSirsERi(%"class.std::basic_istream"* nonnull %28, i32* nonnull dereferenceable(4) %2)
  %30 = bitcast %"class.std::vector.4"* %3 to i8*
  call void @llvm.lifetime.start.p0i8(i64 24, i8* nonnull %30) #9
  %31 = load i32, i32* %1, align 4, !tbaa !30
  %32 = add nsw i32 %31, 1
  %33 = sext i32 %32 to i64
  %34 = icmp slt i32 %31, -1
  br i1 %34, label %35, label %37

35:                                               ; preds = %0
  invoke void @_ZSt20__throw_length_errorPKc(i8* getelementptr inbounds ([49 x i8], [49 x i8]* @.str.4, i64 0, i64 0)) #10
          to label %36 unwind label %217

36:                                               ; preds = %35
  unreachable

37:                                               ; preds = %0
  call void @llvm.memset.p0i8.i64(i8* nonnull align 8 dereferenceable(24) %30, i8 0, i64 24, i1 false) #9
  %38 = icmp eq i32 %32, 0
  br i1 %38, label %44, label %39

39:                                               ; preds = %37
  %40 = mul nuw nsw i64 %33, 24
  %41 = invoke i8* @_Znwm(i64 %40)
          to label %42 unwind label %217

42:                                               ; preds = %39
  %43 = bitcast i8* %41 to %"class.std::vector.9"*
  br label %44

44:                                               ; preds = %42, %37
  %45 = phi %"class.std::vector.9"* [ %43, %42 ], [ null, %37 ]
  %46 = getelementptr inbounds %"class.std::vector.4", %"class.std::vector.4"* %3, i64 0, i32 0, i32 0, i32 0, i32 0
  store %"class.std::vector.9"* %45, %"class.std::vector.9"** %46, align 8, !tbaa !25
  %47 = getelementptr inbounds %"class.std::vector.4", %"class.std::vector.4"* %3, i64 0, i32 0, i32 0, i32 0, i32 1
  store %"class.std::vector.9"* %45, %"class.std::vector.9"** %47, align 8, !tbaa !36
  %48 = getelementptr %"class.std::vector.9", %"class.std::vector.9"* %45, i64 %33
  %49 = getelementptr inbounds %"class.std::vector.4", %"class.std::vector.4"* %3, i64 0, i32 0, i32 0, i32 0, i32 2
  store %"class.std::vector.9"* %48, %"class.std::vector.9"** %49, align 8, !tbaa !37
  br i1 %38, label %53, label %50

50:                                               ; preds = %44
  %51 = bitcast %"class.std::vector.9"* %45 to i8*
  %52 = mul nuw nsw i64 %33, 24
  call void @llvm.memset.p0i8.i64(i8* align 8 %51, i8 0, i64 %52, i1 false)
  br label %53

53:                                               ; preds = %50, %44
  %54 = phi %"class.std::vector.9"* [ %45, %44 ], [ %48, %50 ]
  store %"class.std::vector.9"* %54, %"class.std::vector.9"** %47, align 8, !tbaa !36
  %55 = bitcast %"class.std::vector"* %4 to i8*
  call void @llvm.lifetime.start.p0i8(i64 40, i8* nonnull %55) #9
  %56 = load i32, i32* %1, align 4, !tbaa !30
  %57 = add nsw i32 %56, 1
  %58 = sext i32 %57 to i64
  %59 = getelementptr inbounds %"class.std::vector", %"class.std::vector"* %4, i64 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0
  store i64* null, i64** %59, align 8, !tbaa !23
  %60 = getelementptr inbounds %"class.std::vector", %"class.std::vector"* %4, i64 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 1
  store i32 0, i32* %60, align 8, !tbaa !38
  %61 = getelementptr inbounds %"class.std::vector", %"class.std::vector"* %4, i64 0, i32 0, i32 0, i32 0, i32 1, i32 0, i32 0
  store i64* null, i64** %61, align 8, !tbaa !23
  %62 = getelementptr inbounds %"class.std::vector", %"class.std::vector"* %4, i64 0, i32 0, i32 0, i32 0, i32 1, i32 0, i32 1
  store i32 0, i32* %62, align 8, !tbaa !38
  %63 = getelementptr inbounds %"class.std::vector", %"class.std::vector"* %4, i64 0, i32 0, i32 0, i32 0, i32 2
  store i64* null, i64** %63, align 8, !tbaa !39
  %64 = icmp eq i32 %57, 0
  br i1 %64, label %85, label %65

65:                                               ; preds = %53
  %66 = add nsw i64 %58, 63
  %67 = lshr i64 %66, 6
  %68 = shl nuw nsw i64 %67, 3
  %69 = invoke i8* @_Znwm(i64 %68)
          to label %70 unwind label %98

70:                                               ; preds = %65
  %71 = bitcast i8* %69 to i64*
  %72 = getelementptr inbounds i64, i64* %71, i64 %67
  %73 = bitcast %"class.std::vector"* %4 to i8**
  store i8* %69, i8** %73, align 8
  %74 = sdiv i64 %58, 64
  %75 = getelementptr inbounds i64, i64* %71, i64 %74
  %76 = srem i64 %58, 64
  %77 = icmp slt i64 %76, 0
  %78 = add nsw i64 %76, 64
  %79 = getelementptr inbounds i64, i64* %75, i64 -1
  %80 = select i1 %77, i64* %79, i64* %75
  %81 = select i1 %77, i64 %78, i64 %76
  %82 = trunc i64 %81 to i32
  %83 = insertvalue { i64*, i32 } undef, i64* %80, 0
  %84 = insertvalue { i64*, i32 } %83, i32 %82, 1
  br label %86

85:                                               ; preds = %53
  store i64* null, i64** %59, align 8
  br label %86

86:                                               ; preds = %85, %70
  %87 = phi i64* [ null, %85 ], [ %71, %70 ]
  %88 = phi i64* [ null, %85 ], [ %72, %70 ]
  %89 = phi { i64*, i32 } [ zeroinitializer, %85 ], [ %84, %70 ]
  store i64* %88, i64** %63, align 8
  store i32 0, i32* %60, align 8
  %90 = extractvalue { i64*, i32 } %89, 0
  %91 = extractvalue { i64*, i32 } %89, 1
  store i64* %90, i64** %61, align 8
  store i32 %91, i32* %62, align 8
  %92 = icmp eq i64* %87, null
  br i1 %92, label %102, label %93

93:                                               ; preds = %86
  %94 = ptrtoint i64* %88 to i64
  %95 = bitcast i64* %87 to i8*
  %96 = ptrtoint i64* %87 to i64
  %97 = sub i64 %94, %96
  call void @llvm.memset.p0i8.i64(i8* nonnull align 8 %95, i8 0, i64 %97, i1 false) #9
  br label %102

98:                                               ; preds = %65
  %99 = landingpad { i8*, i32 }
          cleanup
  %100 = extractvalue { i8*, i32 } %99, 0
  %101 = extractvalue { i8*, i32 } %99, 1
  br label %457

102:                                              ; preds = %93, %86
  %103 = bitcast %"class.std::vector.0"* %5 to i8*
  call void @llvm.lifetime.start.p0i8(i64 24, i8* nonnull %103) #9
  %104 = load i32, i32* %1, align 4, !tbaa !30
  %105 = add nsw i32 %104, 1
  %106 = sext i32 %105 to i64
  %107 = icmp slt i32 %104, -1
  br i1 %107, label %108, label %110

108:                                              ; preds = %102
  invoke void @_ZSt20__throw_length_errorPKc(i8* getelementptr inbounds ([49 x i8], [49 x i8]* @.str.4, i64 0, i64 0)) #10
          to label %109 unwind label %221

109:                                              ; preds = %108
  unreachable

110:                                              ; preds = %102
  call void @llvm.memset.p0i8.i64(i8* nonnull align 8 dereferenceable(24) %103, i8 0, i64 24, i1 false) #9
  %111 = icmp eq i32 %105, 0
  br i1 %111, label %117, label %112

112:                                              ; preds = %110
  %113 = shl nuw nsw i64 %106, 3
  %114 = invoke i8* @_Znwm(i64 %113)
          to label %115 unwind label %221

115:                                              ; preds = %112
  %116 = bitcast i8* %114 to i64*
  br label %117

117:                                              ; preds = %115, %110
  %118 = phi i64* [ %116, %115 ], [ null, %110 ]
  %119 = getelementptr inbounds %"class.std::vector.0", %"class.std::vector.0"* %5, i64 0, i32 0, i32 0, i32 0, i32 0
  store i64* %118, i64** %119, align 8, !tbaa !2
  %120 = getelementptr inbounds %"class.std::vector.0", %"class.std::vector.0"* %5, i64 0, i32 0, i32 0, i32 0, i32 1
  store i64* %118, i64** %120, align 8, !tbaa !42
  %121 = getelementptr inbounds i64, i64* %118, i64 %106
  %122 = getelementptr inbounds %"class.std::vector.0", %"class.std::vector.0"* %5, i64 0, i32 0, i32 0, i32 0, i32 2
  store i64* %121, i64** %122, align 8, !tbaa !43
  br i1 %111, label %205, label %123

123:                                              ; preds = %117
  %124 = icmp ult i32 %105, 4
  br i1 %124, label %196, label %125

125:                                              ; preds = %123
  %126 = and i64 %106, -4
  %127 = sub nsw i64 %106, %126
  %128 = getelementptr i64, i64* %118, i64 %126
  %129 = add nsw i64 %126, -4
  %130 = lshr exact i64 %129, 2
  %131 = add nuw nsw i64 %130, 1
  %132 = and i64 %131, 7
  %133 = icmp ult i64 %129, 28
  br i1 %133, label %181, label %134

134:                                              ; preds = %125
  %135 = sub nsw i64 %131, %132
  br label %136

136:                                              ; preds = %136, %134
  %137 = phi i64 [ 0, %134 ], [ %178, %136 ]
  %138 = phi i64 [ %135, %134 ], [ %179, %136 ]
  %139 = getelementptr i64, i64* %118, i64 %137
  %140 = bitcast i64* %139 to <2 x i64>*
  store <2 x i64> <i64 1000000007, i64 1000000007>, <2 x i64>* %140, align 8, !tbaa !7
  %141 = getelementptr i64, i64* %139, i64 2
  %142 = bitcast i64* %141 to <2 x i64>*
  store <2 x i64> <i64 1000000007, i64 1000000007>, <2 x i64>* %142, align 8, !tbaa !7
  %143 = or i64 %137, 4
  %144 = getelementptr i64, i64* %118, i64 %143
  %145 = bitcast i64* %144 to <2 x i64>*
  store <2 x i64> <i64 1000000007, i64 1000000007>, <2 x i64>* %145, align 8, !tbaa !7
  %146 = getelementptr i64, i64* %144, i64 2
  %147 = bitcast i64* %146 to <2 x i64>*
  store <2 x i64> <i64 1000000007, i64 1000000007>, <2 x i64>* %147, align 8, !tbaa !7
  %148 = or i64 %137, 8
  %149 = getelementptr i64, i64* %118, i64 %148
  %150 = bitcast i64* %149 to <2 x i64>*
  store <2 x i64> <i64 1000000007, i64 1000000007>, <2 x i64>* %150, align 8, !tbaa !7
  %151 = getelementptr i64, i64* %149, i64 2
  %152 = bitcast i64* %151 to <2 x i64>*
  store <2 x i64> <i64 1000000007, i64 1000000007>, <2 x i64>* %152, align 8, !tbaa !7
  %153 = or i64 %137, 12
  %154 = getelementptr i64, i64* %118, i64 %153
  %155 = bitcast i64* %154 to <2 x i64>*
  store <2 x i64> <i64 1000000007, i64 1000000007>, <2 x i64>* %155, align 8, !tbaa !7
  %156 = getelementptr i64, i64* %154, i64 2
  %157 = bitcast i64* %156 to <2 x i64>*
  store <2 x i64> <i64 1000000007, i64 1000000007>, <2 x i64>* %157, align 8, !tbaa !7
  %158 = or i64 %137, 16
  %159 = getelementptr i64, i64* %118, i64 %158
  %160 = bitcast i64* %159 to <2 x i64>*
  store <2 x i64> <i64 1000000007, i64 1000000007>, <2 x i64>* %160, align 8, !tbaa !7
  %161 = getelementptr i64, i64* %159, i64 2
  %162 = bitcast i64* %161 to <2 x i64>*
  store <2 x i64> <i64 1000000007, i64 1000000007>, <2 x i64>* %162, align 8, !tbaa !7
  %163 = or i64 %137, 20
  %164 = getelementptr i64, i64* %118, i64 %163
  %165 = bitcast i64* %164 to <2 x i64>*
  store <2 x i64> <i64 1000000007, i64 1000000007>, <2 x i64>* %165, align 8, !tbaa !7
  %166 = getelementptr i64, i64* %164, i64 2
  %167 = bitcast i64* %166 to <2 x i64>*
  store <2 x i64> <i64 1000000007, i64 1000000007>, <2 x i64>* %167, align 8, !tbaa !7
  %168 = or i64 %137, 24
  %169 = getelementptr i64, i64* %118, i64 %168
  %170 = bitcast i64* %169 to <2 x i64>*
  store <2 x i64> <i64 1000000007, i64 1000000007>, <2 x i64>* %170, align 8, !tbaa !7
  %171 = getelementptr i64, i64* %169, i64 2
  %172 = bitcast i64* %171 to <2 x i64>*
  store <2 x i64> <i64 1000000007, i64 1000000007>, <2 x i64>* %172, align 8, !tbaa !7
  %173 = or i64 %137, 28
  %174 = getelementptr i64, i64* %118, i64 %173
  %175 = bitcast i64* %174 to <2 x i64>*
  store <2 x i64> <i64 1000000007, i64 1000000007>, <2 x i64>* %175, align 8, !tbaa !7
  %176 = getelementptr i64, i64* %174, i64 2
  %177 = bitcast i64* %176 to <2 x i64>*
  store <2 x i64> <i64 1000000007, i64 1000000007>, <2 x i64>* %177, align 8, !tbaa !7
  %178 = add i64 %137, 32
  %179 = add i64 %138, -8
  %180 = icmp eq i64 %179, 0
  br i1 %180, label %181, label %136, !llvm.loop !44

181:                                              ; preds = %136, %125
  %182 = phi i64 [ 0, %125 ], [ %178, %136 ]
  %183 = icmp eq i64 %132, 0
  br i1 %183, label %194, label %184

184:                                              ; preds = %181, %184
  %185 = phi i64 [ %191, %184 ], [ %182, %181 ]
  %186 = phi i64 [ %192, %184 ], [ %132, %181 ]
  %187 = getelementptr i64, i64* %118, i64 %185
  %188 = bitcast i64* %187 to <2 x i64>*
  store <2 x i64> <i64 1000000007, i64 1000000007>, <2 x i64>* %188, align 8, !tbaa !7
  %189 = getelementptr i64, i64* %187, i64 2
  %190 = bitcast i64* %189 to <2 x i64>*
  store <2 x i64> <i64 1000000007, i64 1000000007>, <2 x i64>* %190, align 8, !tbaa !7
  %191 = add i64 %185, 4
  %192 = add i64 %186, -1
  %193 = icmp eq i64 %192, 0
  br i1 %193, label %194, label %184, !llvm.loop !46

194:                                              ; preds = %184, %181
  %195 = icmp eq i64 %126, %106
  br i1 %195, label %205, label %196

196:                                              ; preds = %194, %123
  %197 = phi i64 [ %106, %123 ], [ %127, %194 ]
  %198 = phi i64* [ %118, %123 ], [ %128, %194 ]
  br label %199

199:                                              ; preds = %196, %199
  %200 = phi i64 [ %202, %199 ], [ %197, %196 ]
  %201 = phi i64* [ %203, %199 ], [ %198, %196 ]
  store i64 1000000007, i64* %201, align 8, !tbaa !7
  %202 = add i64 %200, -1
  %203 = getelementptr inbounds i64, i64* %201, i64 1
  %204 = icmp eq i64 %202, 0
  br i1 %204, label %205, label %199, !llvm.loop !47

205:                                              ; preds = %199, %194, %117
  %206 = phi i64* [ %118, %117 ], [ %128, %194 ], [ %203, %199 ]
  store i64* %206, i64** %120, align 8, !tbaa !42
  %207 = load i32, i32* %2, align 4, !tbaa !30
  %208 = icmp sgt i32 %207, 0
  br i1 %208, label %209, label %213

209:                                              ; preds = %205
  %210 = bitcast i32* %6 to i8*
  %211 = bitcast i32* %7 to i8*
  %212 = bitcast i64* %8 to i8*
  br label %225

213:                                              ; preds = %327, %205
  %214 = bitcast i32* %9 to i8*
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %214) #9
  %215 = bitcast i32* %10 to i8*
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %215) #9
  %216 = invoke dereferenceable(280) %"class.std::basic_istream"* @_ZNSirsERi(%"class.std::basic_istream"* nonnull @_ZSt3cin, i32* nonnull dereferenceable(4) %9)
          to label %343 unwind label %425

217:                                              ; preds = %39, %35
  %218 = landingpad { i8*, i32 }
          cleanup
  %219 = extractvalue { i8*, i32 } %218, 0
  %220 = extractvalue { i8*, i32 } %218, 1
  br label %475

221:                                              ; preds = %112, %108
  %222 = landingpad { i8*, i32 }
          cleanup
  %223 = extractvalue { i8*, i32 } %222, 0
  %224 = extractvalue { i8*, i32 } %222, 1
  br label %441

225:                                              ; preds = %209, %327
  %226 = phi i32 [ 0, %209 ], [ %330, %327 ]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %210) #9
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %211) #9
  call void @llvm.lifetime.start.p0i8(i64 8, i8* nonnull %212) #9
  %227 = invoke dereferenceable(280) %"class.std::basic_istream"* @_ZNSirsERi(%"class.std::basic_istream"* nonnull @_ZSt3cin, i32* nonnull dereferenceable(4) %6)
          to label %228 unwind label %333

228:                                              ; preds = %225
  %229 = invoke dereferenceable(280) %"class.std::basic_istream"* @_ZNSirsERi(%"class.std::basic_istream"* nonnull %227, i32* nonnull dereferenceable(4) %7)
          to label %230 unwind label %333

230:                                              ; preds = %228
  %231 = invoke dereferenceable(280) %"class.std::basic_istream"* @_ZNSi10_M_extractIxEERSiRT_(%"class.std::basic_istream"* nonnull %229, i64* nonnull dereferenceable(8) %8)
          to label %232 unwind label %333

232:                                              ; preds = %230
  %233 = load i32, i32* %6, align 4, !tbaa !30
  %234 = sext i32 %233 to i64
  %235 = getelementptr inbounds %"class.std::vector.9", %"class.std::vector.9"* %45, i64 %234
  %236 = load i32, i32* %7, align 4, !tbaa !30
  %237 = load i64, i64* %8, align 8, !tbaa !7
  %238 = getelementptr inbounds %"class.std::vector.9", %"class.std::vector.9"* %45, i64 %234, i32 0, i32 0, i32 0, i32 1
  %239 = load %"struct.std::pair"*, %"struct.std::pair"** %238, align 8, !tbaa !49
  %240 = getelementptr inbounds %"class.std::vector.9", %"class.std::vector.9"* %45, i64 %234, i32 0, i32 0, i32 0, i32 2
  %241 = load %"struct.std::pair"*, %"struct.std::pair"** %240, align 8, !tbaa !51
  %242 = icmp eq %"struct.std::pair"* %239, %241
  br i1 %242, label %248, label %243

243:                                              ; preds = %232
  %244 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %239, i64 0, i32 0
  store i32 %236, i32* %244, align 8
  %245 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %239, i64 0, i32 1
  store i64 %237, i64* %245, align 8
  %246 = load %"struct.std::pair"*, %"struct.std::pair"** %238, align 8, !tbaa !49
  %247 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %246, i64 1
  br label %327

248:                                              ; preds = %232
  %249 = ptrtoint %"struct.std::pair"* %239 to i64
  %250 = bitcast %"class.std::vector.9"* %235 to i64*
  %251 = load i64, i64* %250, align 8, !tbaa !52
  %252 = sub i64 %249, %251
  %253 = ashr exact i64 %252, 4
  %254 = icmp eq i64 %252, 9223372036854775792
  %255 = inttoptr i64 %251 to %"struct.std::pair"*
  br i1 %254, label %256, label %258

256:                                              ; preds = %248
  invoke void @_ZSt20__throw_length_errorPKc(i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str.3, i64 0, i64 0)) #10
          to label %257 unwind label %337

257:                                              ; preds = %256
  unreachable

258:                                              ; preds = %248
  %259 = icmp eq i64 %252, 0
  %260 = select i1 %259, i64 1, i64 %253
  %261 = add nsw i64 %260, %253
  %262 = icmp ult i64 %261, %253
  %263 = icmp ugt i64 %261, 576460752303423487
  %264 = or i1 %262, %263
  %265 = select i1 %264, i64 576460752303423487, i64 %261
  %266 = shl nuw nsw i64 %265, 4
  %267 = invoke i8* @_Znwm(i64 %266)
          to label %268 unwind label %335

268:                                              ; preds = %258
  %269 = bitcast i8* %267 to %"struct.std::pair"*
  %270 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %269, i64 %253, i32 0
  store i32 %236, i32* %270, align 8
  %271 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %269, i64 %253, i32 1
  store i64 %237, i64* %271, align 8
  %272 = icmp eq %"struct.std::pair"* %239, %255
  br i1 %272, label %318, label %273

273:                                              ; preds = %268
  %274 = getelementptr %"struct.std::pair", %"struct.std::pair"* %239, i64 -1
  %275 = bitcast %"struct.std::pair"* %274 to i8*
  %276 = sub i64 0, %251
  %277 = getelementptr i8, i8* %275, i64 %276
  %278 = ptrtoint i8* %277 to i64
  %279 = lshr i64 %278, 4
  %280 = add nuw nsw i64 %279, 1
  %281 = and i64 %280, 3
  %282 = icmp eq i64 %281, 0
  br i1 %282, label %293, label %283

283:                                              ; preds = %273, %283
  %284 = phi %"struct.std::pair"* [ %290, %283 ], [ %269, %273 ]
  %285 = phi %"struct.std::pair"* [ %289, %283 ], [ %255, %273 ]
  %286 = phi i64 [ %291, %283 ], [ %281, %273 ]
  %287 = bitcast %"struct.std::pair"* %284 to i8*
  %288 = bitcast %"struct.std::pair"* %285 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* nonnull align 8 dereferenceable(16) %287, i8* nonnull align 8 dereferenceable(16) %288, i64 16, i1 false) #9
  %289 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %285, i64 1
  %290 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %284, i64 1
  %291 = add i64 %286, -1
  %292 = icmp eq i64 %291, 0
  br i1 %292, label %293, label %283, !llvm.loop !53

293:                                              ; preds = %283, %273
  %294 = phi %"struct.std::pair"* [ undef, %273 ], [ %290, %283 ]
  %295 = phi %"struct.std::pair"* [ %269, %273 ], [ %290, %283 ]
  %296 = phi %"struct.std::pair"* [ %255, %273 ], [ %289, %283 ]
  %297 = icmp ult i8* %277, inttoptr (i64 48 to i8*)
  br i1 %297, label %318, label %298

298:                                              ; preds = %293, %298
  %299 = phi %"struct.std::pair"* [ %316, %298 ], [ %295, %293 ]
  %300 = phi %"struct.std::pair"* [ %315, %298 ], [ %296, %293 ]
  %301 = bitcast %"struct.std::pair"* %299 to i8*
  %302 = bitcast %"struct.std::pair"* %300 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* nonnull align 8 dereferenceable(16) %301, i8* nonnull align 8 dereferenceable(16) %302, i64 16, i1 false) #9
  %303 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %300, i64 1
  %304 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %299, i64 1
  %305 = bitcast %"struct.std::pair"* %304 to i8*
  %306 = bitcast %"struct.std::pair"* %303 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* nonnull align 8 dereferenceable(16) %305, i8* nonnull align 8 dereferenceable(16) %306, i64 16, i1 false) #9
  %307 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %300, i64 2
  %308 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %299, i64 2
  %309 = bitcast %"struct.std::pair"* %308 to i8*
  %310 = bitcast %"struct.std::pair"* %307 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* nonnull align 8 dereferenceable(16) %309, i8* nonnull align 8 dereferenceable(16) %310, i64 16, i1 false) #9
  %311 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %300, i64 3
  %312 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %299, i64 3
  %313 = bitcast %"struct.std::pair"* %312 to i8*
  %314 = bitcast %"struct.std::pair"* %311 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* nonnull align 8 dereferenceable(16) %313, i8* nonnull align 8 dereferenceable(16) %314, i64 16, i1 false) #9
  %315 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %300, i64 4
  %316 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %299, i64 4
  %317 = icmp eq %"struct.std::pair"* %315, %239
  br i1 %317, label %318, label %298

318:                                              ; preds = %293, %298, %268
  %319 = phi %"struct.std::pair"* [ %269, %268 ], [ %294, %293 ], [ %316, %298 ]
  %320 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %319, i64 1
  %321 = icmp eq i64 %251, 0
  br i1 %321, label %324, label %322

322:                                              ; preds = %318
  %323 = inttoptr i64 %251 to i8*
  call void @_ZdlPv(i8* nonnull %323) #9
  br label %324

324:                                              ; preds = %322, %318
  %325 = bitcast %"class.std::vector.9"* %235 to i8**
  store i8* %267, i8** %325, align 8, !tbaa !52
  store %"struct.std::pair"* %320, %"struct.std::pair"** %238, align 8, !tbaa !49
  %326 = getelementptr inbounds %"struct.std::pair", %"struct.std::pair"* %269, i64 %265
  br label %327

327:                                              ; preds = %324, %243
  %328 = phi %"struct.std::pair"** [ %240, %324 ], [ %238, %243 ]
  %329 = phi %"struct.std::pair"* [ %326, %324 ], [ %247, %243 ]
  store %"struct.std::pair"* %329, %"struct.std::pair"** %328, align 8, !tbaa !9
  call void @llvm.lifetime.end.p0i8(i64 8, i8* nonnull %212) #9
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %211) #9
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %210) #9
  %330 = add nuw nsw i32 %226, 1
  %331 = load i32, i32* %2, align 4, !tbaa !30
  %332 = icmp slt i32 %330, %331
  br i1 %332, label %225, label %213

333:                                              ; preds = %230, %228, %225
  %334 = landingpad { i8*, i32 }
          cleanup
  br label %339

335:                                              ; preds = %258
  %336 = landingpad { i8*, i32 }
          cleanup
  br label %339

337:                                              ; preds = %256
  %338 = landingpad { i8*, i32 }
          cleanup
  br label %339

339:                                              ; preds = %335, %337, %333
  %340 = phi { i8*, i32 } [ %334, %333 ], [ %336, %335 ], [ %338, %337 ]
  %341 = extractvalue { i8*, i32 } %340, 0
  %342 = extractvalue { i8*, i32 } %340, 1
  call void @llvm.lifetime.end.p0i8(i64 8, i8* nonnull %212) #9
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %211) #9
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %210) #9
  br label %435

343:                                              ; preds = %213
  %344 = invoke dereferenceable(280) %"class.std::basic_istream"* @_ZNSirsERi(%"class.std::basic_istream"* nonnull %216, i32* nonnull dereferenceable(4) %10)
          to label %345 unwind label %425

345:                                              ; preds = %343
  %346 = call i64 @_ZNSt6chrono3_V212system_clock3nowEv() #9
  %347 = load i32, i32* %9, align 4, !tbaa !30
  %348 = load i32, i32* %10, align 4, !tbaa !30
  invoke void @_Z18OptimizedAlgorithmiiRSt6vectorIbSaIbEERS_IxSaIxEERS_IS_ISt4pairIixESaIS7_EESaIS9_EE(i32 %347, i32 %348, %"class.std::vector"* nonnull dereferenceable(40) %4, %"class.std::vector.0"* nonnull dereferenceable(24) %5, %"class.std::vector.4"* nonnull dereferenceable(24) %3)
          to label %349 unwind label %427

349:                                              ; preds = %345
  %350 = call i64 @_ZNSt6chrono3_V212system_clock3nowEv() #9
  %351 = invoke dereferenceable(272) %"class.std::basic_ostream"* @_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l(%"class.std::basic_ostream"* nonnull dereferenceable(272) @_ZSt4cout, i8* nonnull getelementptr inbounds ([25 x i8], [25 x i8]* @.str.1, i64 0, i64 0), i64 24)
          to label %352 unwind label %429

352:                                              ; preds = %349
  %353 = sub nsw i64 %350, %346
  %354 = invoke dereferenceable(272) %"class.std::basic_ostream"* @_ZNSo9_M_insertIlEERSoT_(%"class.std::basic_ostream"* nonnull @_ZSt4cout, i64 %353)
          to label %355 unwind label %429

355:                                              ; preds = %352
  %356 = invoke dereferenceable(272) %"class.std::basic_ostream"* @_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l(%"class.std::basic_ostream"* nonnull dereferenceable(272) %354, i8* nonnull getelementptr inbounds ([13 x i8], [13 x i8]* @.str.2, i64 0, i64 0), i64 12)
          to label %357 unwind label %429

357:                                              ; preds = %355
  %358 = bitcast %"class.std::basic_ostream"* %354 to i8**
  %359 = load i8*, i8** %358, align 8, !tbaa !31
  %360 = getelementptr i8, i8* %359, i64 -24
  %361 = bitcast i8* %360 to i64*
  %362 = load i64, i64* %361, align 8
  %363 = bitcast %"class.std::basic_ostream"* %354 to i8*
  %364 = getelementptr inbounds i8, i8* %363, i64 %362
  %365 = getelementptr inbounds i8, i8* %364, i64 240
  %366 = bitcast i8* %365 to %"class.std::ctype"**
  %367 = load %"class.std::ctype"*, %"class.std::ctype"** %366, align 8, !tbaa !54
  %368 = icmp eq %"class.std::ctype"* %367, null
  br i1 %368, label %369, label %371

369:                                              ; preds = %357
  invoke void @_ZSt16__throw_bad_castv() #10
          to label %370 unwind label %429

370:                                              ; preds = %369
  unreachable

371:                                              ; preds = %357
  %372 = getelementptr inbounds %"class.std::ctype", %"class.std::ctype"* %367, i64 0, i32 8
  %373 = load i8, i8* %372, align 8, !tbaa !55
  %374 = icmp eq i8 %373, 0
  br i1 %374, label %378, label %375

375:                                              ; preds = %371
  %376 = getelementptr inbounds %"class.std::ctype", %"class.std::ctype"* %367, i64 0, i32 9, i64 10
  %377 = load i8, i8* %376, align 1, !tbaa !16
  br label %385

378:                                              ; preds = %371
  invoke void @_ZNKSt5ctypeIcE13_M_widen_initEv(%"class.std::ctype"* nonnull %367)
          to label %379 unwind label %429

379:                                              ; preds = %378
  %380 = bitcast %"class.std::ctype"* %367 to i8 (%"class.std::ctype"*, i8)***
  %381 = load i8 (%"class.std::ctype"*, i8)**, i8 (%"class.std::ctype"*, i8)*** %380, align 8, !tbaa !31
  %382 = getelementptr inbounds i8 (%"class.std::ctype"*, i8)*, i8 (%"class.std::ctype"*, i8)** %381, i64 6
  %383 = load i8 (%"class.std::ctype"*, i8)*, i8 (%"class.std::ctype"*, i8)** %382, align 8
  %384 = invoke signext i8 %383(%"class.std::ctype"* nonnull %367, i8 signext 10)
          to label %385 unwind label %429

385:                                              ; preds = %379, %375
  %386 = phi i8 [ %377, %375 ], [ %384, %379 ]
  %387 = invoke dereferenceable(272) %"class.std::basic_ostream"* @_ZNSo3putEc(%"class.std::basic_ostream"* nonnull %354, i8 signext %386)
          to label %388 unwind label %429

388:                                              ; preds = %385
  %389 = invoke dereferenceable(272) %"class.std::basic_ostream"* @_ZNSo5flushEv(%"class.std::basic_ostream"* nonnull %387)
          to label %390 unwind label %429

390:                                              ; preds = %388
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %215) #9
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %214) #9
  %391 = icmp eq i64* %118, null
  br i1 %391, label %394, label %392

392:                                              ; preds = %390
  %393 = bitcast i64* %118 to i8*
  call void @_ZdlPv(i8* nonnull %393) #9
  br label %394

394:                                              ; preds = %390, %392
  call void @llvm.lifetime.end.p0i8(i64 24, i8* nonnull %103) #9
  %395 = icmp eq i64* %87, null
  br i1 %395, label %408, label %396

396:                                              ; preds = %394
  %397 = ptrtoint i64* %87 to i64
  %398 = bitcast i64** %63 to i64*
  %399 = load i64, i64* %398, align 8, !tbaa !39
  %400 = sub i64 %399, %397
  %401 = ashr exact i64 %400, 3
  %402 = inttoptr i64 %399 to i64*
  %403 = sub nsw i64 0, %401
  %404 = getelementptr inbounds i64, i64* %402, i64 %403
  %405 = bitcast i64* %404 to i8*
  call void @_ZdlPv(i8* %405) #9
  %406 = getelementptr inbounds %"class.std::vector", %"class.std::vector"* %4, i64 0, i32 0, i32 0, i32 0, i32 1
  %407 = bitcast %"struct.std::_Bit_iterator"* %406 to i8*
  store i64* null, i64** %61, align 8
  store i32 0, i32* %62, align 8
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* nonnull align 8 dereferenceable(12) %55, i8* nonnull align 8 dereferenceable(12) %407, i64 12, i1 false) #9
  store i64* null, i64** %63, align 8, !tbaa !39
  br label %408

408:                                              ; preds = %394, %396
  call void @llvm.lifetime.end.p0i8(i64 40, i8* nonnull %55) #9
  %409 = icmp eq %"class.std::vector.9"* %45, %54
  br i1 %409, label %420, label %410

410:                                              ; preds = %408, %417
  %411 = phi %"class.std::vector.9"* [ %418, %417 ], [ %45, %408 ]
  %412 = getelementptr inbounds %"class.std::vector.9", %"class.std::vector.9"* %411, i64 0, i32 0, i32 0, i32 0, i32 0
  %413 = load %"struct.std::pair"*, %"struct.std::pair"** %412, align 8, !tbaa !52
  %414 = icmp eq %"struct.std::pair"* %413, null
  br i1 %414, label %417, label %415

415:                                              ; preds = %410
  %416 = bitcast %"struct.std::pair"* %413 to i8*
  call void @_ZdlPv(i8* nonnull %416) #9
  br label %417

417:                                              ; preds = %415, %410
  %418 = getelementptr inbounds %"class.std::vector.9", %"class.std::vector.9"* %411, i64 1
  %419 = icmp eq %"class.std::vector.9"* %418, %54
  br i1 %419, label %420, label %410

420:                                              ; preds = %417, %408
  %421 = icmp eq %"class.std::vector.9"* %45, null
  br i1 %421, label %424, label %422

422:                                              ; preds = %420
  %423 = bitcast %"class.std::vector.9"* %45 to i8*
  call void @_ZdlPv(i8* nonnull %423) #9
  br label %424

424:                                              ; preds = %420, %422
  call void @llvm.lifetime.end.p0i8(i64 24, i8* nonnull %30) #9
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %27) #9
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %26) #9
  ret i32 0

425:                                              ; preds = %343, %213
  %426 = landingpad { i8*, i32 }
          cleanup
  br label %431

427:                                              ; preds = %345
  %428 = landingpad { i8*, i32 }
          cleanup
  br label %431

429:                                              ; preds = %369, %379, %378, %355, %352, %349, %388, %385
  %430 = landingpad { i8*, i32 }
          cleanup
  br label %431

431:                                              ; preds = %427, %429, %425
  %432 = phi { i8*, i32 } [ %428, %427 ], [ %430, %429 ], [ %426, %425 ]
  %433 = extractvalue { i8*, i32 } %432, 0
  %434 = extractvalue { i8*, i32 } %432, 1
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %215) #9
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %214) #9
  br label %435

435:                                              ; preds = %431, %339
  %436 = phi i8* [ %341, %339 ], [ %433, %431 ]
  %437 = phi i32 [ %342, %339 ], [ %434, %431 ]
  %438 = icmp eq i64* %118, null
  br i1 %438, label %441, label %439

439:                                              ; preds = %435
  %440 = bitcast i64* %118 to i8*
  call void @_ZdlPv(i8* nonnull %440) #9
  br label %441

441:                                              ; preds = %439, %435, %221
  %442 = phi i8* [ %223, %221 ], [ %436, %435 ], [ %436, %439 ]
  %443 = phi i32 [ %224, %221 ], [ %437, %435 ], [ %437, %439 ]
  call void @llvm.lifetime.end.p0i8(i64 24, i8* nonnull %103) #9
  %444 = icmp eq i64* %87, null
  br i1 %444, label %457, label %445

445:                                              ; preds = %441
  %446 = ptrtoint i64* %87 to i64
  %447 = bitcast i64** %63 to i64*
  %448 = load i64, i64* %447, align 8, !tbaa !39
  %449 = sub i64 %448, %446
  %450 = ashr exact i64 %449, 3
  %451 = inttoptr i64 %448 to i64*
  %452 = sub nsw i64 0, %450
  %453 = getelementptr inbounds i64, i64* %451, i64 %452
  %454 = bitcast i64* %453 to i8*
  call void @_ZdlPv(i8* %454) #9
  %455 = getelementptr inbounds %"class.std::vector", %"class.std::vector"* %4, i64 0, i32 0, i32 0, i32 0, i32 1
  %456 = bitcast %"struct.std::_Bit_iterator"* %455 to i8*
  store i64* null, i64** %61, align 8
  store i32 0, i32* %62, align 8
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* nonnull align 8 dereferenceable(12) %55, i8* nonnull align 8 dereferenceable(12) %456, i64 12, i1 false) #9
  store i64* null, i64** %63, align 8, !tbaa !39
  br label %457

457:                                              ; preds = %445, %441, %98
  %458 = phi i8* [ %100, %98 ], [ %442, %441 ], [ %442, %445 ]
  %459 = phi i32 [ %101, %98 ], [ %443, %441 ], [ %443, %445 ]
  call void @llvm.lifetime.end.p0i8(i64 40, i8* nonnull %55) #9
  %460 = icmp eq %"class.std::vector.9"* %45, %54
  br i1 %460, label %471, label %461

461:                                              ; preds = %457, %468
  %462 = phi %"class.std::vector.9"* [ %469, %468 ], [ %45, %457 ]
  %463 = getelementptr inbounds %"class.std::vector.9", %"class.std::vector.9"* %462, i64 0, i32 0, i32 0, i32 0, i32 0
  %464 = load %"struct.std::pair"*, %"struct.std::pair"** %463, align 8, !tbaa !52
  %465 = icmp eq %"struct.std::pair"* %464, null
  br i1 %465, label %468, label %466

466:                                              ; preds = %461
  %467 = bitcast %"struct.std::pair"* %464 to i8*
  call void @_ZdlPv(i8* nonnull %467) #9
  br label %468

468:                                              ; preds = %466, %461
  %469 = getelementptr inbounds %"class.std::vector.9", %"class.std::vector.9"* %462, i64 1
  %470 = icmp eq %"class.std::vector.9"* %469, %54
  br i1 %470, label %471, label %461

471:                                              ; preds = %468, %457
  %472 = icmp eq %"class.std::vector.9"* %45, null
  br i1 %472, label %475, label %473

473:                                              ; preds = %471
  %474 = bitcast %"class.std::vector.9"* %45 to i8*
  call void @_ZdlPv(i8* nonnull %474) #9
  br label %475

475:                                              ; preds = %473, %471, %217
  %476 = phi i8* [ %219, %217 ], [ %458, %471 ], [ %458, %473 ]
  %477 = phi i32 [ %220, %217 ], [ %459, %471 ], [ %459, %473 ]
  call void @llvm.lifetime.end.p0i8(i64 24, i8* nonnull %30) #9
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %27) #9
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %26) #9
  %478 = insertvalue { i8*, i32 } undef, i8* %476, 0
  %479 = insertvalue { i8*, i32 } %478, i32 %477, 1
  resume { i8*, i32 } %479
}

declare dso_local zeroext i1 @_ZNSt8ios_base15sync_with_stdioEb(i1 zeroext) local_unnamed_addr #0

declare dso_local dereferenceable(280) %"class.std::basic_istream"* @_ZNSirsERi(%"class.std::basic_istream"*, i32* dereferenceable(4)) local_unnamed_addr #0

; Function Attrs: nounwind
declare dso_local i64 @_ZNSt6chrono3_V212system_clock3nowEv() local_unnamed_addr #1

; Function Attrs: nobuiltin nounwind
declare dso_local void @_ZdlPv(i8*) local_unnamed_addr #6

declare dso_local dereferenceable(272) %"class.std::basic_ostream"* @_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l(%"class.std::basic_ostream"* dereferenceable(272), i8*, i64) local_unnamed_addr #0

declare dso_local dereferenceable(272) %"class.std::basic_ostream"* @_ZNSo9_M_insertIxEERSoT_(%"class.std::basic_ostream"*, i64) local_unnamed_addr #0

; Function Attrs: argmemonly nounwind willreturn
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #4

; Function Attrs: noreturn
declare dso_local void @_ZSt20__throw_length_errorPKc(i8*) local_unnamed_addr #7

; Function Attrs: nobuiltin nofree
declare dso_local noalias nonnull i8* @_Znwm(i64) local_unnamed_addr #8

; Function Attrs: uwtable
define linkonce_odr dso_local void @_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIxiESt6vectorIS3_SaIS3_EEEElS3_NS0_5__ops15_Iter_comp_iterISt7greaterIS3_EEEEvT_T0_SF_T1_T2_(%"struct.std::pair.19"* %0, i64 %1, i64 %2, i64 %3, i32 %4) local_unnamed_addr #3 comdat {
  %6 = add nsw i64 %2, -1
  %7 = sdiv i64 %6, 2
  %8 = icmp sgt i64 %7, %1
  br i1 %8, label %9, label %36

9:                                                ; preds = %5, %28
  %10 = phi i64 [ %30, %28 ], [ %1, %5 ]
  %11 = shl i64 %10, 1
  %12 = add i64 %11, 2
  %13 = or i64 %11, 1
  %14 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %0, i64 %13, i32 0
  %15 = load i64, i64* %14, align 8, !tbaa !17
  %16 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %0, i64 %12, i32 0
  %17 = load i64, i64* %16, align 8, !tbaa !17
  %18 = icmp slt i64 %15, %17
  br i1 %18, label %27, label %19

19:                                               ; preds = %9
  %20 = icmp slt i64 %17, %15
  br i1 %20, label %28, label %21

21:                                               ; preds = %19
  %22 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %0, i64 %13, i32 1
  %23 = load i32, i32* %22, align 8, !tbaa !19
  %24 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %0, i64 %12, i32 1
  %25 = load i32, i32* %24, align 8, !tbaa !19
  %26 = icmp slt i32 %23, %25
  br i1 %26, label %27, label %28

27:                                               ; preds = %9, %21
  br label %28

28:                                               ; preds = %19, %21, %27
  %29 = phi i64 [ %15, %27 ], [ %17, %21 ], [ %17, %19 ]
  %30 = phi i64 [ %13, %27 ], [ %12, %21 ], [ %12, %19 ]
  %31 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %0, i64 %10, i32 0
  store i64 %29, i64* %31, align 8, !tbaa !17
  %32 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %0, i64 %30, i32 1
  %33 = load i32, i32* %32, align 4, !tbaa !30
  %34 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %0, i64 %10, i32 1
  store i32 %33, i32* %34, align 8, !tbaa !19
  %35 = icmp slt i64 %30, %7
  br i1 %35, label %9, label %36

36:                                               ; preds = %28, %5
  %37 = phi i64 [ %1, %5 ], [ %30, %28 ]
  %38 = and i64 %2, 1
  %39 = icmp eq i64 %38, 0
  br i1 %39, label %40, label %53

40:                                               ; preds = %36
  %41 = add nsw i64 %2, -2
  %42 = sdiv i64 %41, 2
  %43 = icmp eq i64 %37, %42
  br i1 %43, label %44, label %53

44:                                               ; preds = %40
  %45 = shl i64 %37, 1
  %46 = or i64 %45, 1
  %47 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %0, i64 %46, i32 0
  %48 = load i64, i64* %47, align 8, !tbaa !7
  %49 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %0, i64 %37, i32 0
  store i64 %48, i64* %49, align 8, !tbaa !17
  %50 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %0, i64 %46, i32 1
  %51 = load i32, i32* %50, align 4, !tbaa !30
  %52 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %0, i64 %37, i32 1
  store i32 %51, i32* %52, align 8, !tbaa !19
  br label %53

53:                                               ; preds = %44, %40, %36
  %54 = phi i64 [ %46, %44 ], [ %37, %40 ], [ %37, %36 ]
  %55 = icmp sgt i64 %54, %1
  br i1 %55, label %56, label %77

56:                                               ; preds = %53, %72
  %57 = phi i64 [ %59, %72 ], [ %54, %53 ]
  %58 = add nsw i64 %57, -1
  %59 = sdiv i64 %58, 2
  %60 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %0, i64 %59, i32 0
  %61 = load i64, i64* %60, align 8, !tbaa !17
  %62 = icmp sgt i64 %61, %3
  br i1 %62, label %63, label %66

63:                                               ; preds = %56
  %64 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %0, i64 %59, i32 1
  %65 = load i32, i32* %64, align 4, !tbaa !30
  br label %72

66:                                               ; preds = %56
  %67 = icmp slt i64 %61, %3
  br i1 %67, label %77, label %68

68:                                               ; preds = %66
  %69 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %0, i64 %59, i32 1
  %70 = load i32, i32* %69, align 8, !tbaa !19
  %71 = icmp sgt i32 %70, %4
  br i1 %71, label %72, label %77

72:                                               ; preds = %68, %63
  %73 = phi i32 [ %65, %63 ], [ %70, %68 ]
  %74 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %0, i64 %57, i32 0
  store i64 %61, i64* %74, align 8, !tbaa !17
  %75 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %0, i64 %57, i32 1
  store i32 %73, i32* %75, align 8, !tbaa !19
  %76 = icmp sgt i64 %59, %1
  br i1 %76, label %56, label %77

77:                                               ; preds = %66, %68, %72, %53
  %78 = phi i64 [ %54, %53 ], [ %57, %68 ], [ %59, %72 ], [ %57, %66 ]
  %79 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %0, i64 %78, i32 0
  store i64 %3, i64* %79, align 8, !tbaa !17
  %80 = getelementptr inbounds %"struct.std::pair.19", %"struct.std::pair.19"* %0, i64 %78, i32 1
  store i32 %4, i32* %80, align 8, !tbaa !19
  ret void
}

declare dso_local dereferenceable(280) %"class.std::basic_istream"* @_ZNSi10_M_extractIxEERSiRT_(%"class.std::basic_istream"*, i64* dereferenceable(8)) local_unnamed_addr #0

declare dso_local dereferenceable(272) %"class.std::basic_ostream"* @_ZNSo9_M_insertIlEERSoT_(%"class.std::basic_ostream"*, i64) local_unnamed_addr #0

declare dso_local dereferenceable(272) %"class.std::basic_ostream"* @_ZNSo3putEc(%"class.std::basic_ostream"*, i8 signext) local_unnamed_addr #0

declare dso_local dereferenceable(272) %"class.std::basic_ostream"* @_ZNSo5flushEv(%"class.std::basic_ostream"*) local_unnamed_addr #0

; Function Attrs: noreturn
declare dso_local void @_ZSt16__throw_bad_castv() local_unnamed_addr #7

declare dso_local void @_ZNKSt5ctypeIcE13_M_widen_initEv(%"class.std::ctype"*) local_unnamed_addr #0

; Function Attrs: uwtable
define internal void @_GLOBAL__sub_I_dijkstra.cpp() #3 section ".text.startup" {
  tail call void @_ZNSt8ios_base4InitC1Ev(%"class.std::ios_base::Init"* nonnull @_ZStL8__ioinit)
  %1 = tail call i32 @__cxa_atexit(void (i8*)* bitcast (void (%"class.std::ios_base::Init"*)* @_ZNSt8ios_base4InitD1Ev to void (i8*)*), i8* getelementptr inbounds (%"class.std::ios_base::Init", %"class.std::ios_base::Init"* @_ZStL8__ioinit, i64 0, i32 0), i8* nonnull @__dso_handle) #9
  ret void
}

attributes #0 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nofree nounwind }
attributes #3 = { uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { argmemonly nounwind willreturn }
attributes #5 = { norecurse uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #6 = { nobuiltin nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #7 = { noreturn "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #8 = { nobuiltin nofree "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #9 = { nounwind }
attributes #10 = { noreturn }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 10.0.0-4ubuntu1 "}
!2 = !{!3, !4, i64 0}
!3 = !{!"_ZTSNSt12_Vector_baseIxSaIxEE17_Vector_impl_dataE", !4, i64 0, !4, i64 8, !4, i64 16}
!4 = !{!"any pointer", !5, i64 0}
!5 = !{!"omnipotent char", !6, i64 0}
!6 = !{!"Simple C++ TBAA"}
!7 = !{!8, !8, i64 0}
!8 = !{!"long long", !5, i64 0}
!9 = !{!4, !4, i64 0}
!10 = !{!11, !11, i64 0}
!11 = !{!"long", !5, i64 0}
!12 = !{!13, !14, i64 0}
!13 = !{!"_ZTSSt4pairIixE", !14, i64 0, !8, i64 8}
!14 = !{!"int", !5, i64 0}
!15 = !{!13, !8, i64 8}
!16 = !{!5, !5, i64 0}
!17 = !{!18, !8, i64 0}
!18 = !{!"_ZTSSt4pairIxiE", !8, i64 0, !14, i64 8}
!19 = !{!18, !14, i64 8}
!20 = !{!21, !4, i64 8}
!21 = !{!"_ZTSNSt12_Vector_baseISt4pairIxiESaIS1_EE17_Vector_impl_dataE", !4, i64 0, !4, i64 8, !4, i64 16}
!22 = !{!21, !4, i64 0}
!23 = !{!24, !4, i64 0}
!24 = !{!"_ZTSSt18_Bit_iterator_base", !4, i64 0, !14, i64 8}
!25 = !{!26, !4, i64 0}
!26 = !{!"_ZTSNSt12_Vector_baseISt6vectorISt4pairIixESaIS2_EESaIS4_EE17_Vector_impl_dataE", !4, i64 0, !4, i64 8, !4, i64 16}
!27 = !{!21, !4, i64 16}
!28 = distinct !{!28, !29}
!29 = !{!"llvm.loop.unroll.disable"}
!30 = !{!14, !14, i64 0}
!31 = !{!32, !32, i64 0}
!32 = !{!"vtable pointer", !6, i64 0}
!33 = !{!34, !4, i64 216}
!34 = !{!"_ZTSSt9basic_iosIcSt11char_traitsIcEE", !4, i64 216, !5, i64 224, !35, i64 225, !4, i64 232, !4, i64 240, !4, i64 248, !4, i64 256}
!35 = !{!"bool", !5, i64 0}
!36 = !{!26, !4, i64 8}
!37 = !{!26, !4, i64 16}
!38 = !{!24, !14, i64 8}
!39 = !{!40, !4, i64 32}
!40 = !{!"_ZTSNSt13_Bvector_baseISaIbEE18_Bvector_impl_dataE", !41, i64 0, !41, i64 16, !4, i64 32}
!41 = !{!"_ZTSSt13_Bit_iterator"}
!42 = !{!3, !4, i64 8}
!43 = !{!3, !4, i64 16}
!44 = distinct !{!44, !45}
!45 = !{!"llvm.loop.isvectorized", i32 1}
!46 = distinct !{!46, !29}
!47 = distinct !{!47, !48, !45}
!48 = !{!"llvm.loop.unroll.runtime.disable"}
!49 = !{!50, !4, i64 8}
!50 = !{!"_ZTSNSt12_Vector_baseISt4pairIixESaIS1_EE17_Vector_impl_dataE", !4, i64 0, !4, i64 8, !4, i64 16}
!51 = !{!50, !4, i64 16}
!52 = !{!50, !4, i64 0}
!53 = distinct !{!53, !29}
!54 = !{!34, !4, i64 240}
!55 = !{!56, !5, i64 56}
!56 = !{!"_ZTSSt5ctypeIcE", !4, i64 16, !35, i64 24, !4, i64 32, !4, i64 40, !4, i64 48, !5, i64 56, !5, i64 57, !5, i64 313, !5, i64 569}
