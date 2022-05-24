<template>
  <div class="container">
    <div>
      <div
        v-if="!store.wishlist.length"
        class="alert alert-warning display-6 text-center m-5"
        role="alert"
      >
        Your wishlist is empty, add some books!
      </div>
      <table
        v-if="store.wishlist.length"
        class="table table-striped table-bordered mt-4"
      >
        <thead>
          <tr>
            <th>Title</th>
            <th>Author</th>
            <th>No Of Pages</th>
            <th>Price</th>
            <th>Amount</th>
            <th>Total Price</th>
          </tr>
        </thead>
        <tbody>
          <tr v-for="item in store.wishlist" :key="item.ISBN">
            <th>{{ item.book.title }}</th>
            <th>{{ item.book.author }}</th>
            <th>{{ item.book.noOfPages }}</th>
            <th>{{ store.getBookPrice(item.book) }}</th>
            <th>
              <button
                class="btn mx-1 btn-outline-success rounded-circle"
                @click="store.addToWishlist(item.book)"
                :disabled="item.book.stock == 0"
              >
                +
              </button>
              <span class="mx-2">{{ item.amount }}</span>
              <button
                class="btn mx-1 btn-outline-danger rounded-circle"
                @click="store.removeToWishlist(item.book)"
              >
                –
              </button>
            </th>
            <th>{{ store.getTotalPrice(item) }}</th>
          </tr>
        </tbody>
      </table>
    </div>
  </div>
</template>

<script>
import { store } from "../store.js";

export default {
  data: () => ({
    store,
  }),
};
</script>